#include <functional>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/event.h>
#include <wx/dcscreen.h>

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxDefaultSize) {
    this->SetBackgroundColour(this->panel1->GetBackgroundColour());
    this->SetForegroundColour(this->panel1->GetForegroundColour());
    this->panel1->Hide();
    
    this->button1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, [&](wxCommandEvent& event) {
      wxScreenDC screenDC;
      screenDC.SetFont(wxFont(32, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD, false, "Arial"));
      screenDC.SetTextForeground(wxColour(0, 255, 128));
      screenDC.SetBrush(wxBrush(wxColour(0, 0, 0, 0)));
      screenDC.DrawRectangle(10, 100, 300, 50);
      screenDC.DrawText(wxString::Format("cpt click = %d", ++cptClick), { 10, 100 });
    });
  }
private:
  int cptClick = 0;
  wxPanel* panel1 = new wxPanel(this);
  wxButton* button1 = new wxButton(this, wxID_ANY, "Button", { 10, 10 });
};

class Application : public wxApp {
  bool OnInit() override { return (new Form1())->Show(); }
};

wxIMPLEMENT_APP(Application);
