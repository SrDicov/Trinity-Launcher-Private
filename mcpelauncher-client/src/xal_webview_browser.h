#pragma once

#include "xal_webview.h"

#include <string>

class XalWebViewBrowser : public XalWebView {
public:
    virtual std::string show(std::string starturl, std::string endurlprefix) override;

private:
    std::string schemeFromUrl(const std::string& url) const;
    std::string registerSchemeHandler(const std::string& scheme);
    void openInBrowser(const std::string& url);
    std::string readResult(const std::string& callbackFile);
    std::string findInPath(const std::string& name) const;
    std::string runWebView(const std::string& path, const std::string& starturl, const std::string& endurlprefix);
};
