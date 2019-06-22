#include <vector>
#include <wx/wx.h>
#include <wx/Colordlg.h>

using namespace std;

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Main Form", wxPoint(wxSystemSettings::GetMetric(wxSYS_SCREEN_X) - 320, 20), wxSize(300, 300)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxFrame* form = new wxFrame(this, wxID_ANY, *this->iterator, this->location, wxSize(300, 300));
      form->SetBackgroundColour(wxTheColourDatabase->Find(*this->iterator));
      form->Show();
      this->forms.push_back(form);
      
      this->iterator++;
      if (this->iterator == colorNames.end()) this->iterator = colorNames.begin();
      location.x = location.y = location.x < 180 ? location.x + 20 : 20;
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Create", wxPoint(10, 10));
  vector<wxFrame*> forms;
  vector<wxString> colorNames = {"AQUAMARINE", "BLACK", "BLUE", "BLUE VIOLET", "BROWN", "CADET BLUE", "CORAL", "CORNFLOWER BLUE", "CYAN", "DARK GREY", "DARK GREEN", "DARK OLIVE GREEN", "DARK ORCHID", "DARK SLATE BLUE", "DARK SLATE GREY", "DARK TURQUOISE", "DIM GREY", "FIREBRICK", "FOREST GREEN", "GOLD", "GOLDENROD", "GREY", "GREEN", "GREEN YELLOW", "INDIAN RED", "KHAKI", "LIGHT BLUE", "LIGHT GREY", "LIGHT STEEL BLUE", "LIME GREEN", "MAGENTA", "MAROON", "MEDIUM AQUAMARINE", "MEDIUM BLUE", "MEDIUM FOREST GREEN", "MEDIUM GOLDENROD", "MEDIUM ORCHID", "MEDIUM SEA GREEN", "MEDIUM SLATE BLUE", "MEDIUM SPRING GREEN", "MEDIUM TURQUOISE", "MEDIUM VIOLET RED", "MIDNIGHT BLUE", "NAVY", "ORANGE", "ORANGE RED", "ORCHID", "PALE GREEN", "PINK", "PLUM", "PURPLE", "RED", "SALMON", "SEA GREEN", "SIENNA", "SKY BLUE", "SLATE BLUE", "SPRING GREEN", "STEEL BLUE", "TAN", "THISTLE", "TURQUOISE", "VIOLET", "VIOLET RED", "WHEAT", "WHITE", "YELLOW", "YELLOW GREEN"};
  vector<wxString>::iterator iterator = colorNames.begin();
  wxPoint location {20, 20};
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
