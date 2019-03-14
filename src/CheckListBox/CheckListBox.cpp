#include <wx/wx.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "CheckedListBox example", wxDefaultPosition, wxSize(300, 300)) {
    for (int i = 1; i <= 1000; ++i) {
      this->checkedListBox->Insert(wxString::Format("Item %d", i), i - 1);
      this->checkedListBox->Check(i - 1, i % 2 != 0);
    }
    this->Show();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxCheckListBox* checkedListBox = new wxCheckListBox(this->panel, wxID_ANY, wxPoint(20, 20), wxSize(160, 200));
};

class Application : public wxApp {
public:
  bool OnInit() override {new Form(); return true;}
};

wxIMPLEMENT_APP(Application);
