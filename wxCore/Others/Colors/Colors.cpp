#include <wx/wx.h>
#include <map>

using namespace std;

namespace ColorsExample {
  class PanelColor : public wxPanel {
  public:
    PanelColor(wxWindow* parent, const wxColour& color, const wxString& name) : wxPanel(parent) {
      SetMinSize(wxSize(200, 40));
      colourPanel->SetBackgroundColour(color);
      //colourNameStaticText->SetForegroundColour(color.GetLuminance() < 0.5 ? *wxWHITE : *wxBLACK);
      colourNameStaticText->SetLabel(name);
    }
    
  private:
    wxPanel* colourPanel = new wxPanel(this, wxID_ANY, {5, 4}, {100, 32});
    wxStaticText* colourNameStaticText = new wxStaticText(this, wxID_ANY, wxEmptyString, {115, 15});
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Colors example", wxDefaultPosition, {400, 250}) {
      panelMain->SetScrollRate(10, 10);
      panelMain->SetSizerAndFit(boxSizerMain);
      panelMain->SetVirtualSize(boxSizerMain->GetSize());
      
      auto colours = wxTheColourDatabase->GetAllNames();
      std::sort(colours.begin(), colours.end());
      for (auto color : colours) {
        PanelColor* panelColor = new PanelColor(panelMain, wxColour {color}, color);
        boxSizerMain->Add(panelColor, 0, wxGROW);
        panelColors.push_back(panelColor);
      }

      auto colors = map<wxSystemColour, wxString> {
        {wxSYS_COLOUR_SCROLLBAR, "wxSYS_COLOUR_SCROLLBAR"},
        {wxSYS_COLOUR_DESKTOP, "wxSYS_COLOUR_DESKTOP"},
        {wxSYS_COLOUR_ACTIVECAPTION, "wxSYS_COLOUR_ACTIVECAPTION"},
        {wxSYS_COLOUR_INACTIVECAPTION, "wxSYS_COLOUR_INACTIVECAPTION"},
        {wxSYS_COLOUR_MENU, "wxSYS_COLOUR_MENU"},
        {wxSYS_COLOUR_WINDOW, "wxSYS_COLOUR_WINDOW"},
        {wxSYS_COLOUR_WINDOWFRAME, "wxSYS_COLOUR_WINDOWFRAME"},
        {wxSYS_COLOUR_MENUTEXT, "wxSYS_COLOUR_MENUTEXT"},
        {wxSYS_COLOUR_WINDOWTEXT, "wxSYS_COLOUR_WINDOWTEXT"},
        {wxSYS_COLOUR_CAPTIONTEXT, "wxSYS_COLOUR_CAPTIONTEXT"},
        {wxSYS_COLOUR_ACTIVEBORDER, "wxSYS_COLOUR_ACTIVEBORDER"},
        {wxSYS_COLOUR_INACTIVEBORDER, "wxSYS_COLOUR_INACTIVEBORDER"},
        {wxSYS_COLOUR_APPWORKSPACE, "wxSYS_COLOUR_APPWORKSPACE"},
        {wxSYS_COLOUR_HIGHLIGHT, "wxSYS_COLOUR_HIGHLIGHT"},
        {wxSYS_COLOUR_HIGHLIGHTTEXT, "wxSYS_COLOUR_HIGHLIGHTTEXT"},
        {wxSYS_COLOUR_BTNFACE, "wxSYS_COLOUR_BTNFACE"},
        {wxSYS_COLOUR_BTNSHADOW, "wxSYS_COLOUR_BTNSHADOW"},
        {wxSYS_COLOUR_GRAYTEXT, "wxSYS_COLOUR_GRAYTEXT"},
        {wxSYS_COLOUR_BTNTEXT, "wxSYS_COLOUR_BTNTEXT"},
        {wxSYS_COLOUR_INACTIVECAPTIONTEXT, "wxSYS_COLOUR_INACTIVECAPTIONTEXT"},
        {wxSYS_COLOUR_BTNHIGHLIGHT, "wxSYS_COLOUR_BTNHIGHLIGHT"},
        {wxSYS_COLOUR_3DDKSHADOW, "wxSYS_COLOUR_3DDKSHADOW"},
        {wxSYS_COLOUR_3DLIGHT, "wxSYS_COLOUR_3DLIGHT"},
        {wxSYS_COLOUR_INFOTEXT, "wxSYS_COLOUR_INFOTEXT"},
        {wxSYS_COLOUR_INFOBK, "wxSYS_COLOUR_INFOBK"},
        {wxSYS_COLOUR_LISTBOX, "wxSYS_COLOUR_LISTBOX"},
        {wxSYS_COLOUR_HOTLIGHT, "wxSYS_COLOUR_HOTLIGHT"},
        {wxSYS_COLOUR_GRADIENTACTIVECAPTION, "wxSYS_COLOUR_GRADIENTACTIVECAPTION"},
        {wxSYS_COLOUR_GRADIENTINACTIVECAPTION, "wxSYS_COLOUR_GRADIENTINACTIVECAPTION"},
        {wxSYS_COLOUR_MENUHILIGHT, "wxSYS_COLOUR_MENUHILIGHT"},
        {wxSYS_COLOUR_MENUBAR, "wxSYS_COLOUR_MENUBAR"},
        {wxSYS_COLOUR_LISTBOXTEXT, "wxSYS_COLOUR_LISTBOXTEXT"},
        {wxSYS_COLOUR_LISTBOXHIGHLIGHTTEXT, "wxSYS_COLOUR_LISTBOXHIGHLIGHTTEXT"},
      };
      
      for (auto color : colors) {
        PanelColor* panelColor = new PanelColor(panelMain, wxSystemSettings::GetColour(color.first), color.second);
        boxSizerMain->Add(panelColor, 0, wxGROW);
        panelColors.push_back(panelColor);
      }
      
      panelMain->Layout();
    }
    
  private:
    wxBoxSizer* boxSizerMain = new wxBoxSizer(wxVERTICAL);
    wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel>(this);
    vector<PanelColor*> panelColors;
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ColorsExample::Application);
