#include <iostream>
#include <wx/wx.h>
#include <wx/vscroll.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxSize(300, 300)) {
    this->panel->Fit();
    this->panel->Refresh();
    wxSizer* sizer = this->panel->GetSizer();
    if (sizer) sizer->Layout();
  }
  
  bool ProcessEvent (wxEvent &event) override {
    if (event.GetEventType() == wxEVT_CREATE) {
      std::cout << "event {WM_CREATE}" << std::endl;
    }
    else if (event.GetEventType() == wxEVT_DESTROY) std::cout << "event {WM_DESTROY}" << std::endl;
    else if (event.GetEventType() == wxEVT_LEFT_DOWN) std::cout << "event {WM_LBUTTON_DOWN}" << std::endl;
    else if (event.GetEventType() == wxEVT_LEFT_UP) std::cout << "event {WM_LBUTTON_UP}" << std::endl;

    //else std::cout << "event {" << std::hex << event.GetEventType() << "}" << std::endl;
    
    return this->wxFrame::ProcessEvent(event);
  }

private:
  wxScrolledWindow* panel = new wxScrolledWindow(this);
  wxStaticText* label1 = new wxStaticText(this, wxID_ANY, "Label1", wxPoint(10, 150));
  wxButton* label2 = new wxButton(this, wxID_ANY, "Button", wxPoint(10, 200));
};

class Application : public wxApp {
  bool OnInit() override {return true; /*(new Form())->Show();*/}
};

wxIMPLEMENT_APP(Application);
