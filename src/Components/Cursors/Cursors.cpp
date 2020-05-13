#include <wx/wx.h>
#include <string>
#include <vector>

#ifndef __WXMAC__
#  define wxCURSOR_COPY_ARROW wxCURSOR_ARROW
#endif
#ifndef __X__
#  define wxCURSOR_CROSS_REVERSE wxCURSOR_CROSS
#  define wxCURSOR_DOUBLE_ARROW wxCURSOR_ARROW
#  define wxCURSOR_BASED_ARROW_UP wxCURSOR_ARROW
#endif

namespace Examples {
  class Frame : public wxFrame {
    class CursorNamePair {
    public:
      CursorNamePair() {}
      CursorNamePair(wxStockCursor cursor, const std::string& name) : cursor(cursor), name(name)  {}
      
      wxStockCursor Cursor() const {return cursor;}
      const std::string& Name() const {return name;}
      
    private:
      wxStockCursor cursor = wxCURSOR_DEFAULT;
      std::string name = "Default";
    };

  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Cursor example") {
      SetClientSize(360, 240);
      
      for (auto& cursorNamePair : cursorNamePairs)
        listBoxCursors->Append(cursorNamePair.Name(), &cursorNamePair);
          
      listBoxCursors->SetSelection(0);
      listBoxCursors->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, [&](wxCommandEvent& event) {
        testZone->SetCursor(static_cast<CursorNamePair*>(listBoxCursors->wxItemContainer::GetClientData(listBoxCursors->GetSelection()))->Cursor());
      });
      
      testZone->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
    }
    
  private:
    std::vector<CursorNamePair> cursorNamePairs = {{wxCURSOR_ARROW, "Arrow"}, {wxCURSOR_RIGHT_ARROW, "Right arrow"}, {wxCURSOR_BULLSEYE, "Bulls eye"}, {wxCURSOR_CHAR, "Char"}, {wxCURSOR_CROSS, "Cross"}, {wxCURSOR_HAND, "Hand"}, {wxCURSOR_IBEAM, "IBeam"}, {wxCURSOR_LEFT_BUTTON, "Left button"}, {wxCURSOR_MAGNIFIER, "Magnifier"}, {wxCURSOR_MIDDLE_BUTTON, "Middle button"}, {wxCURSOR_NO_ENTRY, "No entry"}, {wxCURSOR_PAINT_BRUSH, "Paint brush"}, {wxCURSOR_PENCIL, "Pencil"}, {wxCURSOR_POINT_LEFT, "Point left"}, {wxCURSOR_POINT_RIGHT, "Point right"}, {wxCURSOR_QUESTION_ARROW, "Question arrow"}, {wxCURSOR_RIGHT_BUTTON, "Right button"}, {wxCURSOR_SIZENESW, "sizenorth-east south-west"}, {wxCURSOR_SIZENS, "size north south"}, {wxCURSOR_SIZENWSE, "Size north-west south-east"}, {wxCURSOR_SIZEWE, "Size west east"}, {wxCURSOR_SIZING, "Sizing"}, {wxCURSOR_SPRAYCAN, "Spraycan"}, {wxCURSOR_WAIT, "Wait"}, {wxCURSOR_WATCH, "Watch"}, {wxCURSOR_BLANK, "Blank"}, {wxCURSOR_DEFAULT, "Default"}, {wxCURSOR_COPY_ARROW, "Copy arrow"}, {wxCURSOR_CROSS_REVERSE, "Cross reverse"}, {wxCURSOR_DOUBLE_ARROW, "Double arrow"}, {wxCURSOR_BASED_ARROW_UP, "Based arrow up"}, {wxCURSOR_ARROWWAIT, "Arrow wait"}, {wxCURSOR_OPEN_HAND, "Open hand"}, {wxCURSOR_CLOSED_HAND, "Closed hand"}};
    wxPanel* panel = new wxPanel(this);
    wxListBox* listBoxCursors = new wxListBox(panel, wxID_ANY, {20, 20}, {150, 200});
    wxPanel* testZone = new wxPanel(panel, wxID_ANY, {190, 20}, {150, 200}, wxBORDER_SUNKEN);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
