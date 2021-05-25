#include <memory>
#include <stdexcept>
#include "Application.h"
#include <wx/wx.h>
#include <wx/graphics.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
  }

private:
  wxPanel* panel = new wxPanel {this};
  wxImage image {8, 8};
};

int main() {
  auto application = new wxApplication;
  auto frame = new MainFrame;
  frame->Show();
  application->MainLoop();
}
