#include <map>
#include <string>
#include <vector>
#include <wx/wx.h>

namespace Examples {
  class PanelColor : public wxPanel {
  public:
    PanelColor(wxWindow* parent, const wxColour& color, const std::string& name) : wxPanel(parent) {
      SetMinSize(wxSize(100, 50));
      SetBackgroundColour(color);
      staticTextColorName->SetLabel(name);
    }
    
  private:
    wxStaticText* staticTextColorName = new wxStaticText(this, wxID_ANY, wxEmptyString);
  };

  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Colors example", wxDefaultPosition, {400, 250}) {
      panelMain->SetScrollRate(10, 10);
      panelMain->SetSizerAndFit(boxSizerMain);
      panelMain->SetVirtualSize(boxSizerMain->GetSize());
      
      PanelColor* panelColor = new PanelColor(panelMain, wxColor(255, 0, 0), "Red");
      boxSizerMain->Add(panelColor, 0, wxGROW);
      panelColors.push_back(panelColor);
      
      PanelColor* panelColor2 = new PanelColor(panelMain, wxColor(0, 255, 0), "Green");
      boxSizerMain->Add(panelColor2, 0, wxGROW);
      panelColors.push_back(panelColor2);
      
      PanelColor* panelColor3 = new PanelColor(panelMain, wxColor(0, 0, 255), "Blue");
      boxSizerMain->Add(panelColor3, 0, wxGROW);
      panelColors.push_back(panelColor3);
      
      std::map<wxSystemColour, std::string> colors = {
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
        wxMessageOutputDebug().Printf("%s => 0x%X", color.second, wxSystemSettings::GetColour(color.first).GetRGBA());
      }

      panelMain->Layout();
    }
    
  private:
    wxBoxSizer* boxSizerMain = new wxBoxSizer(wxVERTICAL);
    wxScrolled<wxPanel>* panelMain = new wxScrolled<wxPanel>(this);
    std::vector<PanelColor*> panelColors;
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
