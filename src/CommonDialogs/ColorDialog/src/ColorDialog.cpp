#include <wx/wx.h>
#include <wx/colordlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ColorDialog example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxColourData colorData;
      colorData.SetColour(GetBackgroundColour());
      wxColourDialog colorDialog(this, &colorData);
      if (colorDialog.ShowModal()) {
        SetBackgroundColour(colorDialog.GetColourData().GetColour());
        Refresh();
      }
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Color...", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
