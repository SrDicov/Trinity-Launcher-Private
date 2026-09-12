#include "xal_webview_browser.h"
#include "util.h"

#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

#include <chrono>
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

namespace
{

constexpr int kWaitTimeoutSeconds = 300;
constexpr int kPollIntervalMs = 200;

std::string HomeDir()
{
    const char* home = std::getenv("HOME");
    return home ? home : "";
}

std::string RuntimeDir()
{
    const char* runtime = std::getenv("XDG_RUNTIME_DIR");
    if (runtime && *runtime)
        return runtime;
    return "/tmp";
}

std::string CallbackFile()
{
    return RuntimeDir() + "/mcpelauncher-xal-callback.url";
}

bool RunNoShell(const std::vector<std::string>& args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        std::vector<char*> argv;
        argv.reserve(args.size() + 1);
        for (auto& arg : args)
            argv.push_back(const_cast<char*>(arg.c_str()));
        argv.push_back(nullptr);
        execvp(argv[0], argv.data());
        _exit(127);
    }
    if (pid < 0)
        return false;
    int status;
    waitpid(pid, &status, 0);
    return WIFEXITED(status) && WEXITSTATUS(status) == 0;
}

std::string ReadCallbackFile(const std::string& path)
{
    std::ifstream in(path);
    if (!in.is_open())
        return {};
    std::string result;
    std::getline(in, result);
    trim(result);
    return result;
}

std::vector<std::string> BrowserCandidates()
{
    std::vector<std::string> candidates;
    const char* browserEnv = std::getenv("BROWSER");
    if (browserEnv && *browserEnv)
    {
        std::stringstream ss(browserEnv);
        std::string cmd;
        while (std::getline(ss, cmd, ':'))
        {
            if (!cmd.empty())
                candidates.push_back(cmd);
        }
    }
    candidates.emplace_back("/opt/waterfox/waterfox");
    candidates.emplace_back("/usr/bin/waterfox");
    candidates.emplace_back("/usr/local/bin/waterfox");
    candidates.emplace_back("/usr/bin/firefox");
    candidates.emplace_back("/opt/firefox/firefox");
    candidates.emplace_back("/usr/bin/falkon");
    candidates.emplace_back("/usr/bin/librewolf");
    candidates.emplace_back("/opt/librewolf/librewolf");
    candidates.emplace_back("/usr/bin/brave");
    candidates.emplace_back("/usr/bin/brave-browser");
    candidates.emplace_back("/opt/brave.com/brave/brave-browser");
    candidates.emplace_back("/usr/bin/chromium");
    candidates.emplace_back("/usr/bin/chromium-browser");
    candidates.emplace_back("/usr/bin/google-chrome");
    candidates.emplace_back("/usr/bin/google-chrome-stable");
    candidates.emplace_back("/opt/google/chrome/chrome");
    candidates.emplace_back("/usr/bin/ungoogled-chromium");
    candidates.emplace_back("/usr/bin/ungoogled-chromium-browser");
    candidates.emplace_back("/opt/ungoogled-chromium/ungoogled-chromium");
    return candidates;
}

bool LaunchDetached(const std::vector<std::string>& args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        if (fork() != 0)
            _exit(0);
        setsid();
        int devnull = open("/dev/null", O_RDWR);
        if (devnull >= 0)
        {
            dup2(devnull, STDIN_FILENO);
            dup2(devnull, STDOUT_FILENO);
            dup2(devnull, STDERR_FILENO);
            close(devnull);
        }
        std::vector<char*> argv;
        argv.reserve(args.size() + 1);
        for (auto& arg : args)
            argv.push_back(const_cast<char*>(arg.c_str()));
        argv.push_back(nullptr);
        execvp(argv[0], argv.data());
        _exit(127);
    }
    if (pid < 0)
        return false;
    waitpid(pid, nullptr, 0);
    return true;
}

} // namespace

std::string XalWebViewBrowser::schemeFromUrl(const std::string& url) const
{
    auto colon = url.find(':');
    if (colon == std::string::npos)
        return {};
    return url.substr(0, colon);
}

std::string XalWebViewBrowser::registerSchemeHandler(const std::string& scheme)
{
    if (scheme.empty())
        return {};

    std::string dataDir = HomeDir() + "/.local/share";
    std::string appDir = dataDir + "/applications";
    std::string binDir = dataDir + "/mcpelauncher";
    mkdir(appDir.c_str(), 0755);
    mkdir(binDir.c_str(), 0755);

    std::string callbackFile = CallbackFile();
    unlink(callbackFile.c_str());

    std::string scriptPath = binDir + "/xal-capture.sh";
    {
        std::ofstream out(scriptPath);
        if (!out.is_open())
            return {};
        out << "#!/bin/sh\n"
            << "echo \"$1\" > \"" << callbackFile << "\"\n";
    }
    chmod(scriptPath.c_str(), 0755);

    std::string desktopPath = appDir + "/mcpelauncher-xal.desktop";
    {
        std::ofstream out(desktopPath);
        if (!out.is_open())
            return {};
        out << "[Desktop Entry]\n"
            << "Type=Application\n"
            << "Name=Minecraft Xal Login\n"
            << "Comment=Handles the final redirect of the Minecraft Xbox Live sign in flow\n"
            << "Exec=" << scriptPath << " %u\n"
            << "NoDisplay=true\n"
            << "MimeType=x-scheme-handler/" << scheme << ";\n";
    }
    chmod(desktopPath.c_str(), 0644);

    RunNoShell({ "xdg-mime", "default", "mcpelauncher-xal.desktop",
        "x-scheme-handler/" + scheme });

    std::ifstream mimeCache(appDir + "/mimeinfo.cache");
    bool needsUpdate = true;
    if (mimeCache.is_open())
    {
        std::string line;
        while (std::getline(mimeCache, line))
        {
            if (line.find("x-scheme-handler/" + scheme) != std::string::npos)
            {
                needsUpdate = false;
                break;
            }
        }
    }
    if (needsUpdate)
        RunNoShell({ "update-desktop-database", appDir });
    return callbackFile;
}

void XalWebViewBrowser::openInBrowser(const std::string& url)
{
    if (RunNoShell({ "xdg-open", url }))
        return;

    for (const auto& browser : BrowserCandidates())
    {
        if (browser.empty())
            continue;
        std::vector<std::string> args;
        if (browser.find('/') == std::string::npos)
        {
            args.push_back("/bin/sh");
            args.push_back("-c");
            args.push_back(browser + " \"" + url + "\"");
        }
        else
        {
            args.push_back(browser);
            args.push_back(url);
        }
        LaunchDetached(args);
        return;
    }
}

std::string XalWebViewBrowser::findInPath(const std::string& name) const
{
    if (name.find('/') != std::string::npos)
        return (access(name.c_str(), X_OK) == 0) ? name : std::string();

    const char* pathEnv = std::getenv("PATH");
    if (!pathEnv)
        return {};

    std::stringstream ss(pathEnv);
    std::string dir;
    while (std::getline(ss, dir, ':'))
    {
        if (dir.empty())
            dir = ".";
        std::string candidate = dir + "/" + name;
        if (access(candidate.c_str(), X_OK) == 0)
            return candidate;
    }
    return {};
}

std::string XalWebViewBrowser::runWebView(const std::string& path,
    const std::string& starturl, const std::string& endurlprefix)
{
    int stdoutPipe[2];
    if (pipe(stdoutPipe) != 0)
        return {};

    pid_t pid = fork();
    if (pid == 0)
    {
        dup2(stdoutPipe[1], STDOUT_FILENO);
        int devnull = open("/dev/null", O_WRONLY);
        if (devnull >= 0)
        {
            dup2(devnull, STDERR_FILENO);
            close(devnull);
        }
        close(stdoutPipe[0]);
        close(stdoutPipe[1]);

        std::vector<std::string> args = { path, starturl, endurlprefix };
        std::vector<char*> argv;
        argv.reserve(args.size() + 1);
        for (auto& arg : args)
            argv.push_back(const_cast<char*>(arg.c_str()));
        argv.push_back(nullptr);
        execv(argv[0], argv.data());
        _exit(127);
    }
    if (pid < 0)
    {
        close(stdoutPipe[0]);
        close(stdoutPipe[1]);
        return {};
    }

    close(stdoutPipe[1]);
    std::string output;
    char buf[1024];
    ssize_t r;
    while ((r = read(stdoutPipe[0], buf, sizeof(buf))) > 0)
        output.append(buf, (size_t)r);
    close(stdoutPipe[0]);

    int status;
    waitpid(pid, &status, 0);
    trim(output);
    return output;
}

std::string XalWebViewBrowser::readResult(const std::string& callbackFile)
{
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(kWaitTimeoutSeconds);
    bool stdinClosed = false;

    while (std::chrono::steady_clock::now() < deadline)
    {
        if (!callbackFile.empty())
        {
            std::string result = ReadCallbackFile(callbackFile);
            if (!result.empty())
                return result;
        }

        if (!stdinClosed)
        {
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(STDIN_FILENO, &fds);
            struct timeval tv = { 0, kPollIntervalMs * 1000 };
            int ready = select(STDIN_FILENO + 1, &fds, nullptr, nullptr, &tv);
            if (ready > 0 && FD_ISSET(STDIN_FILENO, &fds))
            {
                std::string line;
                std::getline(std::cin, line);
                if (std::cin.eof())
                    stdinClosed = true;
                trim(line);
                if (!line.empty())
                    return line;
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(kPollIntervalMs));
    }

    return {};
}

std::string XalWebViewBrowser::show(std::string starturl, std::string endurlprefix)
{
    std::string webviewPath = findInPath("mcpelauncher-webview");
    if (webviewPath.empty())
        webviewPath = findInPath("lite-webview");
    if (!webviewPath.empty())
    {
        std::cout << "[XalWebView] using webview binary: " << webviewPath << "\n";
        std::string result = runWebView(webviewPath, starturl, endurlprefix);
        if (!result.empty() && result.rfind(endurlprefix, 0) == 0)
            return result;
    }

    std::string scheme = schemeFromUrl(endurlprefix);
    std::string callbackFile = registerSchemeHandler(scheme);
    if (callbackFile.empty())
        callbackFile = CallbackFile(); // host may already have the scheme handler; poll the fixed path anyway

    std::cout << "[XalWebView] starturl=" << starturl << "\n";
    std::cout << "[XalWebView] endurlprefix=" << endurlprefix << "\n";
    std::cout << "Opening \"" << starturl << "\" in your default browser...\n";
    std::cout << "After that, the final URL (starting with \"" << endurlprefix
              << "\") is captured automatically.\n";
    std::cout << "If it is not captured, paste the final URL here and press Enter:\n";

    openInBrowser(starturl);

    std::string result = readResult(callbackFile);
    if (result.empty())
    {
        std::cout << "Timed out waiting for the sign in result.\n";
        return "";
    }
    if (result.rfind(endurlprefix, 0) != 0)
    {
        std::cout << "Got a result that does not start with \"" << endurlprefix << "\": " << result << "\n";
        return "";
    }
    return result;
}
