#include <wx/wx.h>

class Application : public wxApp {
public:
  bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, ""))->Show(); return true;}
  bool ProcessIdle() override {
    static int counter = 0;
    this->GetTopWindow()->SetLabel(wxString::Format("%d", ++counter));
    return wxApp::ProcessIdle();
  }
};

wxIMPLEMENT_APP(Application);
