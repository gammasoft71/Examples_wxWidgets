#include <map>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/menuitem.h>
#include <wx/panel.h>
#include <wx/srchctrl.h>
#include <wx/stattext.h>

enum FruitID {
  ID_TEXT = 1,
  ID_REFERENCES,
  ID_DEFINITIONS,
  ID_REGULAR_EXPRESSION
};

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "SearchCtrl example") {
      SetClientSize(300, 300);
      
      menuSearch->AppendRadioItem(ID_TEXT, "Text");
      menuSearch->AppendRadioItem(ID_REFERENCES, "References");
      menuSearch->AppendRadioItem(ID_DEFINITIONS, "Definitions");
      menuSearch->AppendRadioItem(ID_REGULAR_EXPRESSION, "Regular expression");

      wxArrayString fruits;
      fruits.Add("Apple");
      fruits.Add("Banana");
      fruits.Add("Pear");
      fruits.Add("Raspberry");
      searchCtrl1->AutoComplete(fruits);
      searchCtrl1->ShowCancelButton(true);
      searchCtrl1->SetMenu(menuSearch);
      searchCtrl1->Bind(wxEVT_SEARCH, [&](wxCommandEvent& event) {
        staticText2->SetLabel(wxString::Format("Search for : %s", searchCtrl1->GetValue()));
      });
      
      searchCtrl1->GetMenu()->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        std::map<int, std::string> modes = {{ID_TEXT, "Text"}, {ID_REFERENCES, "References"}, {ID_DEFINITIONS, "Definitions"}, {ID_REGULAR_EXPRESSION, "Regular expression"}};
        staticText1->SetLabel(wxString::Format("Mode : %s", modes[event.GetId()]));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxSearchCtrl* searchCtrl1 = new wxSearchCtrl(panel, wxID_ANY, wxEmptyString, {10, 10}, {280, wxDefaultCoord});
    wxStaticText* staticText1 = new wxStaticText(panel, wxID_ANY, "Mode : Text", {10, 50}, {280, 20});
    wxStaticText* staticText2 = new wxStaticText(panel, wxID_ANY, "Search for : ", {10, 80}, {280, 50});
    wxMenu* menuSearch = new wxMenu();
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
