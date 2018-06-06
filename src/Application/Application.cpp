#include <wx/wx.h>

class Application : public wxApp {
public:
  bool OnInit() override {
    this->form = new wxFrame(nullptr, wxID_ANY, "");
    this->form->Show(true);
    return true;
  }
  
private:
  wxFrame* form;
};

wxIMPLEMENT_APP(Application);
