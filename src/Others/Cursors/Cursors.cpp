#include <wx/wx.h>
#include <string>
#include <vector>

class Form : public wxFrame {
  class CursorNamePair {
  public:
    CursorNamePair() {}
    CursorNamePair(wxStockCursor cursor, wxString name) : cursor(cursor), name(name)  {}
    
    wxStockCursor Cursor() const {return cursor;}
    wxString Name() const {return name;}
    
  private:
    wxStockCursor cursor = wxCURSOR_DEFAULT;
    wxString name = "Default";
  };

public:
  Form() : wxFrame(nullptr, wxID_ANY, "Cursor example", wxDefaultPosition) {
    SetClientSize(wxSize(360, 240));
    for (auto& cursorNamePair : cursorNamePairs)
      listBoxCursors->Append(cursorNamePair.Name(), &cursorNamePair);
        
    listBoxCursors->SetSelection(3);
    listBoxCursors->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, [&](wxCommandEvent& event) {
      testZone->SetCursor(static_cast<CursorNamePair*>(listBoxCursors->wxItemContainer::GetClientData(listBoxCursors->GetSelection()))->Cursor());
    });
    
    testZone->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
  }
  
private:
  std::vector<CursorNamePair> cursorNamePairs = {{wxCURSOR_ARROWWAIT, "AppStart"}, {wxCURSOR_ARROW, "Arrow"}, {wxCURSOR_CROSS, "Cross"}, {wxCURSOR_DEFAULT, "Default"}, {wxCURSOR_HAND, "Hand"}, {wxCURSOR_QUESTION_ARROW , "Help"}, {wxCURSOR_SIZENS , "HSplit"}, {wxCURSOR_IBEAM , "IBeam"}, {wxCURSOR_NO_ENTRY , "No"}, {wxCURSOR_NO_ENTRY , "NoMove2D"}, {wxCURSOR_NO_ENTRY , "NoMoveHoriz"}, {wxCURSOR_NO_ENTRY , "NoMoveVert"}, {wxCURSOR_ARROW, "PanEsat"}, {wxCURSOR_ARROW, "PanNE"}, {wxCURSOR_ARROW, "PanNorth"}, {wxCURSOR_ARROW, "PanNW"}, {wxCURSOR_ARROW, "PanSE"}, {wxCURSOR_ARROW, "PanSouth"}, {wxCURSOR_ARROW, "PanSW"}, {wxCURSOR_ARROW, "PanWest"}, {wxCURSOR_SIZING, "sizeAll"}, {wxCURSOR_SIZENESW, "sizeNESW"}, {wxCURSOR_SIZENS, "sizeNS"}, {wxCURSOR_SIZENWSE, "sizeNWSE"}, {wxCURSOR_SIZEWE, "sizeWE"}, {wxCURSOR_ARROW, "UpArrow"}, {wxCURSOR_SIZEWE, "VSplit"}, {wxCURSOR_WAIT, "WaitCursor"}};
  wxPanel* panel = new wxPanel(this);
  wxListBox* listBoxCursors = new wxListBox(panel, wxID_ANY, wxPoint(20, 20), wxSize(150, 200));
  wxPanel* testZone = new wxPanel(panel, wxID_ANY, wxPoint(190, 20), wxSize(150, 200), wxBORDER_SUNKEN);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
