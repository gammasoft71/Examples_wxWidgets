#include <wx/wx.h>
#include <wx/webview.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "WebBrowser example", wxDefaultPosition) {
    Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      webBrowser->SetSize(GetClientSize());
    });
    SetClientSize(1024, 768);
    webBrowser->SetSize(GetClientSize());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxWebView* webBrowser = wxWebView::New(panel, wxID_ANY, "https://gammasoft71.wixsite.com/gammasoft");
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
