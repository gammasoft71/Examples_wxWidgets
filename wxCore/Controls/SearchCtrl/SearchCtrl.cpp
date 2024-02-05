#include <wx/app.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/menuitem.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/stattext.h>
#include <map>

using namespace std;

namespace SearchCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "SearchCtrl example"} {
      menuSearch->AppendRadioItem(ID_TEXT, "Text");
      menuSearch->AppendRadioItem(ID_REFERENCES, "References");
      menuSearch->AppendRadioItem(ID_DEFINITIONS, "Definitions");
      menuSearch->AppendRadioItem(ID_REGULAR_EXPRESSION, "Regular expression");

      auto items = vector<wxString> {"Apple", "Banana", "Pear", "Raspberry"};
      searchCtrl1->AutoComplete(wxArrayString(static_cast<int>(items.size()), items.data()));
      searchCtrl1->ShowCancelButton(true);
      searchCtrl1->SetMenu(menuSearch);
      searchCtrl1->Bind(wxEVT_SEARCH, [&](wxCommandEvent& event) {
        staticText2->SetLabel(wxString::Format("Search for : %s", searchCtrl1->GetValue()));
      });
      
      searchCtrl1->GetMenu()->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static auto modes = map<int, wxString> {{ID_TEXT, "Text"}, {ID_REFERENCES, "References"}, {ID_DEFINITIONS, "Definitions"}, {ID_REGULAR_EXPRESSION, "Regular expression"}};
        staticText1->SetLabel(wxString::Format("Mode : %s", modes[event.GetId()]));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxSearchCtrl* searchCtrl1 = new wxSearchCtrl {panel, wxID_ANY, wxEmptyString, {10, 10}, {280, wxDefaultCoord}};
    wxStaticText* staticText1 = new wxStaticText {panel, wxID_ANY, "Mode : Text", {10, 50}, {280, 20}};
    wxStaticText* staticText2 = new wxStaticText {panel, wxID_ANY, "Search for : ", {10, 80}, {280, 50}};
    wxMenu* menuSearch = new wxMenu();
    
    inline static const int ID_TEXT = 1;
    inline static const int ID_REFERENCES = 2;
    inline static const int ID_DEFINITIONS = 3;
    inline static const int ID_REGULAR_EXPRESSION = 4;
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(SearchCtrlExample::Application);
