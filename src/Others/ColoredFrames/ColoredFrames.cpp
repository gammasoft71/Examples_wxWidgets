#include <vector>
#include <wx/wx.h>
#include <wx/colordlg.h>

using namespace std;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Main Window", {wxSystemSettings::GetMetric(wxSYS_SCREEN_X) - 420, 40}) {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        auto frame = new wxFrame(this, wxID_ANY, *colorNamesIterator, location);
        frame->SetBackgroundColour(wxTheColourDatabase->Find(*colorNamesIterator));
        frame->Show();
        frames.push_back(frame);

        colorNamesIterator++;
        if (colorNamesIterator == colorNames.end()) colorNamesIterator = colorNames.begin();
        location.x = location.y = location.x < 180 ? location.x + 20 : 20;
      });
    }

  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Create", {10, 10});
    vector<wxFrame*> frames;
    vector<wxString> colorNames {"AQUAMARINE", "BLACK", "BLUE", "BLUE VIOLET", "BROWN", "CADET BLUE", "CORAL", "CORNFLOWER BLUE", "CYAN", "DARK GREY", "DARK GREEN", "DARK OLIVE GREEN", "DARK ORCHID", "DARK SLATE BLUE", "DARK SLATE GREY", "DARK TURQUOISE", "DIM GREY", "FIREBRICK", "FOREST GREEN", "GOLD", "GOLDENROD", "GREY", "GREEN", "GREEN YELLOW", "INDIAN RED", "KHAKI", "LIGHT BLUE", "LIGHT GREY", "LIGHT STEEL BLUE", "LIME GREEN", "MAGENTA", "MAROON", "MEDIUM AQUAMARINE", "MEDIUM BLUE", "MEDIUM FOREST GREEN", "MEDIUM GOLDENROD", "MEDIUM ORCHID", "MEDIUM SEA GREEN", "MEDIUM SLATE BLUE", "MEDIUM SPRING GREEN", "MEDIUM TURQUOISE", "MEDIUM VIOLET RED", "MIDNIGHT BLUE", "NAVY", "ORANGE", "ORANGE RED", "ORCHID", "PALE GREEN", "PINK", "PLUM", "PURPLE", "RED", "SALMON", "SEA GREEN", "SIENNA", "SKY BLUE", "SLATE BLUE", "SPRING GREEN", "STEEL BLUE", "TAN", "THISTLE", "TURQUOISE", "VIOLET", "VIOLET RED", "WHEAT", "WHITE", "YELLOW", "YELLOW GREEN"};
    vector<wxString>::iterator colorNamesIterator = colorNames.begin();
    wxPoint location {20, 20};
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
