#include <vector>
#include <wx/wx.h>
#include <wx/colordlg.h>

using namespace std;

namespace ColourDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ColourDialog example") {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto colourData = wxColourData {};
        colourData.SetColour(GetBackgroundColour());
        for (auto index = 0; index < static_cast<int>(customColours.size()); index++)
          colourData.SetCustomColour(index, customColours[index]);
        auto colourDialog = wxColourDialog {this, &colourData};
        if (colourDialog.ShowModal() == wxID_OK) {
          SetBackgroundColour(colourDialog.GetColourData().GetColour());
          Refresh();
        }
        for (auto index = 0; index < static_cast<int>(customColours.size()); index++)
          customColours[index], colourData.GetCustomColour(index);
      });
    }

  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Color...", {10, 10}};
    vector<wxColour> customColours {{0xFF, 0x00, 0x00}, {0x00, 0xFF, 0x00}, {0x00, 0x00, 0xFF}, {0xFF, 0xFF, 0x00}, {0xF0, 0xF0, 0xF0}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF}};
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ColourDialogExample::Application);
