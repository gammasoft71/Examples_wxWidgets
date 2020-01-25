#include <wx/app.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBitmap2 example") {
      SetClientSize(300, 300);
      wxInitAllImageHandlers();
      staticBitmap1->SetBitmap({"Resources/Logo.png", wxBITMAP_TYPE_ANY});
      staticBitmap1->SetWindowStyle(wxBORDER_SIMPLE);
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticBitmap* staticBitmap1 = new wxStaticBitmap(this, wxID_ANY, wxNullBitmap, {20, 20}, {100, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
