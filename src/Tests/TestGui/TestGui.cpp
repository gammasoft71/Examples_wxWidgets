#include <functional>
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/settings.h>

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxDefaultSize) {
    this->SetBackgroundColour(this->panel1->GetBackgroundColour());
    this->SetForegroundColour(this->panel1->GetForegroundColour());
    this->panel1->Hide();

    wxFont sysFont = wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT);
    sysFont.SetPointSize(sysFont.GetPointSize() * 4.0 / 3.0);

    this->button1->SetFont(wxSystemSettings::GetFont(wxSystemFont::wxSYS_DEFAULT_GUI_FONT));
    this->button3->SetFont(wxFont(wxOSXSystemFont::wxOSX_SYSTEM_FONT_VIEWS));
    this->button4->SetFont(sysFont);
    
  }
private:
  wxPanel* panel1 = new wxPanel(this);
  wxButton* button1 = new wxButton(this, wxID_ANY, "Button", { 10, 10 });
  wxButton* button2 = new wxButton(this, wxID_ANY, "Button", { 10, 40 });
  wxButton* button3 = new wxButton(this, wxID_ANY, "Button", { 10, 70 });
  wxButton* button4 = new wxButton(this, wxID_ANY, "Button", { 10, 100 });
};

class Application : public wxApp {
  bool OnInit() override {
    wxMenu* menuWindow = new wxMenu();
    wxMenuItem* aboutMenuItem = new wxMenuItem(menuWindow, wxID_ANY, "About");

    wxMenuBar* menubar = new wxMenuBar();
    menubar->Append(menuWindow, "Window");
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_ABOUT) wxAboutBox(wxAboutDialogInfo());
      else event.Skip();
    });

    wxApp::s_macAboutMenuItemId = aboutMenuItem->GetId();
    wxApp::s_macWindowMenuTitleName = "Window";
    wxMenuBar::MacSetCommonMenuBar(menubar);
    return (new Form1())->Show();
  }
};

wxIMPLEMENT_APP(Application);
