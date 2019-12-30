#include <wx/wx.h>
#include <wx/webview.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "WebView example") {
    Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      webView->SetSize(GetClientSize());
    });
    SetClientSize(1024, 768);
    webView->SetSize(GetClientSize());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxWebView* webView = wxWebView::New(panel, wxID_ANY, "https://gammasoft71.wixsite.com/gammasoft");
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
