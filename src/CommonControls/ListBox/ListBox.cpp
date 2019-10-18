#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ListBox example", wxDefaultPosition, wxSize(300, 300)) {
    SetClientSize(360, 240);
    
    listBoxLeft->SetSize(150, 200);
    listBoxLeft->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
      listBoxRight->Append(listBoxLeft->GetStringSelection());
      listBoxRight->SetSelection(0);
      listBoxLeft->Delete(listBoxLeft->GetSelection());
    });

    listBoxRight->SetSize(150, 200);
    listBoxRight->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
      listBoxLeft->Append(listBoxRight->GetStringSelection());
      listBoxLeft->SetSelection(0);
      listBoxRight->Delete(listBoxRight->GetSelection());
    });
    
    for (auto& item : {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"})
      listBoxLeft->Append(item);
    listBoxLeft->SetSelection(0);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxListBox* listBoxLeft = new wxListBox(panel, wxID_ANY, wxPoint(20, 20));
  wxListBox* listBoxRight = new wxListBox(panel, wxID_ANY, wxPoint(190, 20), wxDefaultSize, 0, nullptr, wxLB_SORT);
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
