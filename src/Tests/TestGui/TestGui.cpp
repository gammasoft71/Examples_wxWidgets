#include <stdexcept>
#include "Application.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      //throw std::invalid_argument("Not a valid argument");
      throw "anything...";
    });
  }
  
private:
  wxPanel* panel = new wxPanel {this};
  wxButton* button = new wxButton(panel, wxID_ANY, "Exception", {10, 10});
};

int main() {
  try {
    auto application = new wxApplication;
    auto frame = new MainFrame;
    frame->Show();
    application->MainLoop();
  } catch(const std::exception& e) {
    wxMessageBox(wxString::Format("Message: %s\n", e.what()), "Exception occured", wxOK);
  } catch(...) {
    wxMessageBox("Message: (none)", "Unknown exception occured", wxOK);
  }
}
