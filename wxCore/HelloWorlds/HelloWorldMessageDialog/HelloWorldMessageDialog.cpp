#include <wx/wx.h>

class Application : public wxApp {
  bool OnInit() override {
    auto frame1 = new wxFrame(nullptr, wxID_ANY, "Hello World (message box)");
    
    auto panel1 = new wxPanel(frame1, wxID_ANY);
    
    auto button1 = new wxButton(panel1, wxID_ANY, "Click me", {10, 10});
    button1->Bind(wxEVT_BUTTON, [](wxCommandEvent&) {
      wxMessageDialog(nullptr, "Hello, World!").ShowModal();
    });
    
    frame1->Show();
    return true;
  }
};

wxIMPLEMENT_APP(Application);
