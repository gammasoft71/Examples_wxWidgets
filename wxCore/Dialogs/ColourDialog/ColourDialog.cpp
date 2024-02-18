#include <wx/app.h>
#include <wx/button.h>
#include <wx/colordlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <vector>

using namespace std;

namespace ColourDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ColourDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto colourData = wxColourData {};
        colourData.SetColour(selectedColor);
        for (auto index = 0; index < static_cast<int>(customColours.size()); index++)
          colourData.SetCustomColour(index, customColours[index]);
        auto colourDialog = wxColourDialog {this, &colourData};
        if (colourDialog.ShowModal() == wxID_OK) {
          selectedColor = colourDialog.GetColourData().GetColour();
          testZone->SetBackgroundColour(selectedColor);
          testZone->Refresh();
          colorText->SetLabel(selectedColor.GetAsString(wxC2S_HTML_SYNTAX));
        }
        for (auto index = 0; index < static_cast<int>(customColours.size()); index++)
          customColours[index], colourData.GetCustomColour(index);
      });

      testZone->SetBackgroundColour(selectedColor);
      colorText->SetLabel(selectedColor.GetAsString(wxC2S_HTML_SYNTAX));
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Color...", {10, 10}};
    wxPanel* testZone = new wxPanel {panel, wxID_ANY, {10, 50}, {200, 100}, wxBORDER_SUNKEN | wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL};
    wxStaticText* colorText = new wxStaticText {panel, wxID_ANY, wxEmptyString, {10, 160}};
    wxColour selectedColor = wxTheColourDatabase->Find("red");
    vector<wxColour> customColours {{0xFF, 0x00, 0x00}, {0x00, 0xFF, 0x00}, {0x00, 0x00, 0xFF}, {0xFF, 0xFF, 0x00}, {0xF0, 0xF0, 0xF0}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ColourDialogExample::Application);
