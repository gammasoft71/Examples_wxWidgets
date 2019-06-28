#include <wx/wx.h>
#include <wx/webview.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "WebBrowser example", wxDefaultPosition) {
    this->Bind(wxEVT_SIZING, [&](wxSizeEvent& event) {
      this->webBrowser->SetSize(this->GetClientSize());
    });
    this->SetClientSize(1024, 768);
    this->webBrowser->SetSize(this->GetClientSize());
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxWebView* webBrowser = wxWebView::New(this->panel, wxID_ANY, "https://gammasoft71.wixsite.com/gammasoft");
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
