#include <wx/wx.h>
#include <wx/webview.h>

namespace WebViewExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "WebView example", wxDefaultPosition, {1024, 768}) {}
    
  private:
    wxWebView* webView = wxWebView::New(this, wxID_ANY, "https://docs.wxwidgets.org/latest/");
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(WebViewExample::Application);
