#include <wx/app.h>
#include <wx/checklst.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CheckListBox example") {
      SetClientSize({200, 240});
      for (auto i = 1; i <= 20; ++i) {
        checkListBox->Append(wxString::Format("Item %d", i));
        checkListBox->Check(i - 1, i % 2 != 0);
        checkListBox->EnsureVisible(0);
      }
      checkListBox->SetSelection(0);
      checkListBox->Bind(wxEVT_CHECKLISTBOX, [&](wxCommandEvent& e) {
        wxArrayInt checkedIndexes;
        checkListBox->GetCheckedItems(checkedIndexes);
        wxString checkedItems;
        for (auto index : checkedIndexes)
          checkedItems.Append(wxString::Format("%s%s", checkedItems != wxEmptyString ? ", " : "", checkListBox->GetString(index)));
        wxMessageOutputDebug().Printf("checked items = {%s}", checkedItems);
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxCheckListBox* checkListBox = new wxCheckListBox(panel, wxID_ANY, {20, 20}, {160, 200});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
