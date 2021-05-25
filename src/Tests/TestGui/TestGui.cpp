#include "Application.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
  }

private:
  wxPanel* panel = new wxPanel {this};
};

int main() {
  auto application = new wxApplication;
  application->MainLoop(new MainFrame);
}
