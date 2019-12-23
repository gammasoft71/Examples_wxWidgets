#include <wx/wx.h>

class Application : public wxApp {
  bool OnInit() override {(new wxFrame(nullptr, wxID_ANY, wxEmptyString))->Show(); return true;}
  
  int FilterEvent(wxEvent &event) override {
    static int counter = 0;
    wxMessageOutputDebug().Printf("coutner = %d", ++counter);
    return wxApp::FilterEvent(event);
  }
};

wxIMPLEMENT_APP(Application);
