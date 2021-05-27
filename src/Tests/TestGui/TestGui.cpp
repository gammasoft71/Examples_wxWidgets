#include "Application.h"
#include <wx/wx.h>
#include <wx/display.h>
#include <wx/log.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
    button->Bind(wxEVT_BUTTON, [](wxCommandEvent& e) {
      wxLogMessage("Processus error");
    });
  }

private:
  wxPanel* mainPanel = new wxPanel {this};
  wxButton* button = new wxButton {mainPanel, wxID_ANY, "Click", {10, 10}};
};

int main() {
  auto application = new wxApplication;
  application->MainLoop(new MainFrame);
}
