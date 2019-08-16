#include <functional>
#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/settings.h>
#include <wx/event.h>

#if defined(WIN32)
#include <Windows.h>
void WriteLineDebugString(const wxString& str) {
  OutputDebugString(str.wc_str());
  OutputDebugString(L"\n");
}
#else
#include <iostream>
void WriteLineDebugString(const wxString& str) {
  std::wcout << str.wc_str() << std::endl;
}
#endif

class Form1 : public wxFrame {
public:
  Form1() : wxFrame(nullptr, wxID_ANY, "Test gui", wxDefaultPosition, wxDefaultSize) {
    this->panel1->Hide();
    WriteLineDebugString(wxString::Format("BackColor = 0x%X", wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).GetRGBA()));
    WriteLineDebugString(wxString::Format("BackColor = 0x%X", this->GetBackgroundColour().GetRGBA()));
    wxColour color(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE).OSXGetNSColor());
    this->SetBackgroundColour(color);
    this->button1->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
      this->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
    });
    //this->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE));
  }
private:
  wxPanel* panel1 = new wxPanel(this);
  wxStaticText* label1 = new wxStaticText(this, wxID_ANY, "Button", {10, 10});
  wxButton* button1 = new wxButton(this, wxID_ANY, "Button", {10, 200});
};

class Application : public wxApp {
  bool OnInit() override {return (new Form1())->Show();}
};

wxIMPLEMENT_APP(Application);
