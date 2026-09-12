#include <string>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

extern "C" {

static std::string g_end_prefix;
static std::string g_matched_url;
static bool g_matched = false;

static void dbg_log(const std::string &msg) {
    int fd = open("/tmp/lite-webview-debug.log",
                  O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
        return;
    write(fd, msg.data(), msg.size());
    write(fd, "\n", 1);
    close(fd);
}

static void finish_capture(const gchar *uri) {
    if (g_matched)
        return;
    std::string u(uri ? uri : "");
    if (g_end_prefix.empty())
        return;
    if (u.rfind(g_end_prefix, 0) != 0)
        return;
    g_matched = true;
    g_matched_url = u;
    dbg_log("MATCH captured: " + u);
    gtk_main_quit();
}

static void on_scheme_request(WebKitURISchemeRequest *request, gpointer userdata) {
    (void)userdata;
    const gchar *uri = webkit_uri_scheme_request_get_uri(request);
    dbg_log(std::string("scheme-request: ") + (uri ? uri : "(null)"));
    finish_capture(uri);
    GError *err = g_error_new_literal(g_quark_from_static_string("webview"), 1,
                                      "captured");
    webkit_uri_scheme_request_finish_error(request, err);
    g_error_free(err);
}

static gboolean on_decide_policy(WebKitWebView *web_view,
                                 WebKitPolicyDecision *decision,
                                 gpointer userdata) {
    (void)web_view;
    (void)userdata;
    if (WEBKIT_IS_NAVIGATION_POLICY_DECISION(decision)) {
        WebKitNavigationPolicyDecision *nav =
            WEBKIT_NAVIGATION_POLICY_DECISION(decision);
        WebKitNavigationAction *action =
            webkit_navigation_policy_decision_get_navigation_action(nav);
        WebKitURIRequest *req = webkit_navigation_action_get_request(action);
        const gchar *uri = req ? webkit_uri_request_get_uri(req) : nullptr;
        dbg_log(std::string("decide-policy navigation: ") +
                (uri ? uri : "(null)"));
        if (uri && g_end_prefix.size() &&
            std::string(uri).rfind(g_end_prefix, 0) == 0) {
            finish_capture(uri);
            webkit_policy_decision_ignore(decision);
            return TRUE;
        }
    }
    return FALSE;
}

const char *mcperun_webview_run(const char *start, const char *end_prefix) {
    g_matched_url.clear();
    g_matched = false;
    g_end_prefix = end_prefix ? end_prefix : "";

    dbg_log(std::string("start= ") + (start ? start : "(null)") +
            " end_prefix= " + g_end_prefix);

    gtk_init(nullptr, nullptr);

    WebKitWebContext *wctx = webkit_web_context_get_default();
    std::string scheme;
    if (!g_end_prefix.empty()) {
        auto colon = g_end_prefix.find(':');
        if (colon != std::string::npos) {
            scheme = g_end_prefix.substr(0, colon);
        }
    }
    dbg_log("registering scheme: " + (scheme.empty() ? std::string("(none)") : scheme));
    if (!scheme.empty()) {
        webkit_web_context_register_uri_scheme(wctx, scheme.c_str(),
                                               on_scheme_request, nullptr,
                                               nullptr);
    }

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Xbox Live Login");
    gtk_window_set_default_size(GTK_WINDOW(window), 1100, 750);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), nullptr);

    WebKitWebView *wv = reinterpret_cast<WebKitWebView *>(webkit_web_view_new());
    g_signal_connect(wv, "decide-policy", G_CALLBACK(on_decide_policy), nullptr);
    gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(wv));
    gtk_widget_show_all(window);

    if (start) {
        dbg_log("loading start: " + std::string(start));
        webkit_web_view_load_uri(wv, start);
    }

    gtk_main();
    gtk_widget_destroy(window);

    return g_matched ? g_matched_url.c_str() : nullptr;
}

} // extern "C"
