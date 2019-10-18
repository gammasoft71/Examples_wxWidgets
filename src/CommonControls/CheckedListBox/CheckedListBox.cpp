#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "CheckedListBox example", wxDefaultPosition, wxSize(300, 300)) {
    SetClientSize(200, 240);
    for (int i = 1; i <= 20; ++i) {
      checkedListBox->Append(wxString::Format("Item %d", i));
      checkedListBox->Check(i - 1, i % 2 != 0);
      checkedListBox->EnsureVisible(0);
    }
    checkedListBox->SetSelection(0);
    checkedListBox->Bind(wxEVT_CHECKLISTBOX, [this](wxCommandEvent& e) {
      wxArrayInt checkedIndexes;
      checkedListBox->GetCheckedItems(checkedIndexes);
      wxString checkedItems;
      for (int index : checkedIndexes)
        checkedItems.Append(wxString::Format("%s%s", checkedItems != wxEmptyString ? ", " : "", checkedListBox->GetString(index)));
      wxMessageOutputDebug().Printf("checked items = {%s}", checkedItems);
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCheckListBox* checkedListBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(20, 20), wxSize(160, 200));
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
