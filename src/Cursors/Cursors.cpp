#include <wx/wx.h>
#include <string>
#include <vector>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "Cursor example", wxDefaultPosition, wxSize(360, 260)) {
    for (auto& cursorNamePair : this->cursorNamePairs)
      this->listBoxCursors->Insert(cursorNamePair.Name(), this->listBoxCursors->GetCount(), &cursorNamePair);
    
    this->listBoxCursors->Bind(wxEVT_COMMAND_LISTBOX_SELECTED, [&](wxCommandEvent& event) {
      this->testZone->SetCursor(static_cast<CursorNamePair*>(this->listBoxCursors->wxItemContainer::GetClientData(this->listBoxCursors->GetSelection()))->Cursor());
    });
    
    this->listBoxCursors->SetSelection(3);
    
    this->testZone->SetBackgroundColour(wxTheColourDatabase->Find("White"));
    this->testZone->SetWindowStyle(wxBORDER_RAISED);
    this->Show();
  }
  
private:
  class CursorNamePair {
  public:
    CursorNamePair() {}
    CursorNamePair(wxStockCursor cursor, std::string name) : cursor(cursor), name(name)  {}
    
    wxStockCursor Cursor() const {return this->cursor;}
    std::string Name() const {return this->name;}
    
  private:
    wxStockCursor cursor = wxCURSOR_DEFAULT;
    std::string name = "Default";
  };

  std::vector<CursorNamePair> cursorNamePairs = {{wxCURSOR_WAIT, "AppStart"}, {wxCURSOR_ARROW, "Arrow"}, {wxCURSOR_CROSS, "Cross"}, {wxCURSOR_DEFAULT, "Default"}, {wxCURSOR_HAND, "Hand"}, {wxCURSOR_QUESTION_ARROW , "Help"}, {wxCURSOR_SIZENS , "HSplit"}, {wxCURSOR_IBEAM , "IBeam"}, {wxCURSOR_NO_ENTRY , "No"}, {wxCURSOR_NO_ENTRY , "NoMove2D"}, {wxCURSOR_NO_ENTRY , "NoMoveHoriz"}, {wxCURSOR_NO_ENTRY , "NoMoveVert"}, {wxCURSOR_ARROW, "PanEsat"}, {wxCURSOR_ARROW, "PanNE"}, {wxCURSOR_ARROW, "PanNorth"}, {wxCURSOR_ARROW, "PanNW"}, {wxCURSOR_ARROW, "PanSE"}, {wxCURSOR_ARROW, "PanSouth"}, {wxCURSOR_ARROW, "PanSW"}, {wxCURSOR_ARROW, "PanWest"}, {wxCURSOR_SIZING, "sizeAll"}, {wxCURSOR_SIZENESW, "sizeNESW"}, {wxCURSOR_SIZENS, "sizeNS"}, {wxCURSOR_SIZENWSE, "sizeNWSE"}, {wxCURSOR_SIZEWE, "sizeWE"}, {wxCURSOR_ARROW, "UpArrow"}, {wxCURSOR_SIZEWE, "VSplit"}, {wxCURSOR_WAIT, "WaitCursor"}};
  wxPanel* panel = new wxPanel(this);
  wxListBox* listBoxCursors = new wxListBox(this->panel, wxID_ANY, wxPoint(20, 20), wxSize(150, 200));
  wxPanel* testZone = new wxPanel(this->panel, wxID_ANY, wxPoint(190, 20), wxSize(150, 200));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
