#include <wx/app.h>
#include <wx/checklst.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ChackListBoxExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "CheckListBox example"} {
      SetClientSize({200, 240});
      for (auto index = 1; index <= 10; ++index) {
        checkListBox->Append(wxString::Format("Item %d", index));
        checkListBox->Check(index - 1, index % 2 != 0);
        checkListBox->EnsureVisible(0);
      }
      checkListBox->SetSelection(0);
      checkListBox->Bind(wxEVT_CHECKLISTBOX, [&](wxCommandEvent& e) {
        wxMessageOutputDebug().Printf("checked items = {%s}", CheckListBoxToString());
      });
      
      wxMessageOutputDebug().Printf("checked items = {%s}", CheckListBoxToString());
    }
    
  private:
    wxString CheckListBoxToString() const noexcept {
      auto checkedIndexes = wxArrayInt {};
      checkListBox->GetCheckedItems(checkedIndexes);
      auto checkedItems = wxString {};
      for (auto index : checkedIndexes)
        checkedItems.Append(wxString::Format("%s%s", checkedItems != wxEmptyString ? ", " : "", checkListBox->GetString(index)));
      return checkedItems;
    }
    
    wxPanel* panel = new wxPanel {this};
    wxCheckListBox* checkListBox = new wxCheckListBox {panel, wxID_ANY, {20, 20}, {160, 200}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ChackListBoxExample::Application);
