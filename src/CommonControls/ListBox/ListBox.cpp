#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ListBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->SetClientSize(360, 240);
    
    this->listBoxLeft->SetSize(150, 200);
    this->listBoxLeft->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
      this->listBoxRight->Append(this->listBoxLeft->GetStringSelection());
      this->listBoxRight->SetSelection(this->listBoxRight->GetCount() - 1);
      this->listBoxLeft->Delete(this->listBoxLeft->GetSelection());
    });

    this->listBoxRight->SetSize(150, 200);
    this->listBoxRight->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
      this->listBoxLeft->Append(this->listBoxRight->GetStringSelection());
      this->listBoxLeft->SetSelection(this->listBoxLeft->GetCount() - 1);
      this->listBoxRight->Delete(this->listBoxRight->GetSelection());
    });
    
    for (auto& item : {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"})
      this->listBoxLeft->Append(item);
    this->listBoxLeft->SetSelection(0);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxListBox* listBoxLeft = new wxListBox(this->panel, wxID_ANY, wxPoint(20, 20));
  wxListBox* listBoxRight = new wxListBox(this->panel, wxID_ANY, wxPoint(190, 20));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
