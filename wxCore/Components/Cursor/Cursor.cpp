#include <wx/app.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <utility>
#include <vector>

using namespace std;

namespace CursorExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "Cursors example"} {
      SetClientSize(360, 240);
      
      for (auto& cursorPair : cursorPairs)
        listBoxCursors->Append(cursorPair.first, &cursorPair.second);
          
      listBoxCursors->SetSelection(0);
      listBoxCursors->Bind(wxEVT_LISTBOX, [&](wxCommandEvent& event) {
        testZone->SetCursor(*static_cast<wxStockCursor*>(listBoxCursors->wxItemContainer::GetClientData(listBoxCursors->GetSelection())));
      });
      
      testZone->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
    }
    
  private:
    vector<pair<wxString, wxStockCursor>> cursorPairs = {{"Default", wxCURSOR_DEFAULT}, {"Arrow", wxCURSOR_ARROW}, {"Right arrow", wxCURSOR_RIGHT_ARROW}, {"Bulls eye", wxCURSOR_BULLSEYE}, {"Char", wxCURSOR_CHAR}, {"Cross", wxCURSOR_CROSS}, {"Hand", wxCURSOR_HAND}, {"IBeam", wxCURSOR_IBEAM}, {"Left button", wxCURSOR_LEFT_BUTTON}, {"Magnifier", wxCURSOR_MAGNIFIER}, {"Middle button", wxCURSOR_MIDDLE_BUTTON}, {"No entry", wxCURSOR_NO_ENTRY}, {"Paint brush", wxCURSOR_PAINT_BRUSH}, {"Pencil", wxCURSOR_PENCIL}, {"Point left", wxCURSOR_POINT_LEFT}, {"Point right", wxCURSOR_POINT_RIGHT}, {"Question arrow", wxCURSOR_QUESTION_ARROW}, {"Right button", wxCURSOR_RIGHT_BUTTON}, {"sizenorth-east south-west", wxCURSOR_SIZENESW}, {"size north south", wxCURSOR_SIZENS}, {"Size north-west south-east", wxCURSOR_SIZENWSE}, {"Size west east", wxCURSOR_SIZEWE}, {"Sizing", wxCURSOR_SIZING}, {"Spraycan", wxCURSOR_SPRAYCAN}, {"Wait", wxCURSOR_WAIT}, {"Watch", wxCURSOR_WATCH}, {"Blank", wxCURSOR_BLANK}, {"Arrow wait", wxCURSOR_ARROWWAIT}, {"Open hand", wxCURSOR_OPEN_HAND}, {"Closed hand", wxCURSOR_CLOSED_HAND}};
    wxPanel* panel = new wxPanel {this};
    wxListBox* listBoxCursors = new wxListBox {panel, wxID_ANY, {20, 20}, {150, 200}};
    wxPanel* testZone = new wxPanel {panel, wxID_ANY, {190, 20}, {150, 200}, wxBORDER_SUNKEN};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(CursorExample::Application);
