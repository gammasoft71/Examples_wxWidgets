#include <wx/wx.h>

int main(int argc, char* argv[]) {
  wxFrame form1 = new wxFrame(nullptr, "Form1", wxDefaultPosition, wxSize(300, 300));
  form1->Show();
  wxTheApp->OnRun();
}
