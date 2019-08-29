#include <wx/wx.h>

#if defined(__WXOSX__)
float points_to_native_font_graphics_untit(float size) {
  return size / 0.75f;  // font is in pixels and not in points
}
#else
float points_to_native_font_graphics_untit(float size) {
  return size;  // font is in points
}
#endif

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Timer example", wxDefaultPosition) {
    this->SetClientSize(wxSize(230, 130));
    this->label->SetFont(wxFont(points_to_native_font_graphics_untit(48), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, "Arial"));
    this->label->SetForegroundColour(wxColour(30, 144, 255));

    this->timer.Bind(wxEVT_TIMER, [&](wxTimerEvent& event) {
      this->label->SetLabelText(wxString::Format("%.1f", ++this->counter / 10.0));
    });

    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      if (this->timer.IsRunning())
        this->timer.Stop();
      else
        this->timer.Start(100);
      this->button->SetLabel(this->timer.IsRunning() ? "Stop" : "Start");
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxStaticText* label = new wxStaticText(this->panel, wxID_ANY, "0.0", wxPoint(10, 10), wxSize(220, 70));
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Start", wxPoint(10, 90));
  wxTimer timer;
  int counter = 0;
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
