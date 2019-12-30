#include <wx/wx.h>
#include <wx/colordlg.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ColourDialog example", wxDefaultPosition, {300, 300}) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxColourData colourData;
      colourData.SetColour(GetBackgroundColour());
      wxColourDialog colourDialog(this, &colourData);
      if (colourDialog.ShowModal()) {
        SetBackgroundColour(colourDialog.GetColourData().GetColour());
        Refresh();
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Color...", {10, 10});
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
