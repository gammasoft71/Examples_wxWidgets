#include "Application.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, {800, 450}} {
  }
  
private:
  wxPanel* panel = new wxPanel {this};
};

int main() {
  auto application = new wxApplication;
  auto frame = new MainFrame;
  frame->Show();
  return application->MainLoop();
}
