#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>

using namespace std;

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, {300, 300}) {
    comboBox1->Append(vector<wxString> {"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"});
    comboBox1->Select(0);
    comboBox1->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& e) {
      comboBox2->SetSelection(comboBox1->GetSelection());
      comboBox3->SetSelection(comboBox1->GetSelection());
    });

    comboBox2->Append(vector<wxString> {"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"});
    comboBox2->Select(0);
    comboBox2->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& e) {
      comboBox1->SetSelection(comboBox2->GetSelection());
      comboBox3->SetSelection(comboBox2->GetSelection());
    });

    comboBox3->Append(vector<wxString> {"item1", "item2", "item3", "item4", "item5", "item6", "item7", "item8", "item9", "item10"});
    comboBox3->Select(0);
    comboBox3->Bind(wxEVT_COMBOBOX, [this](wxCommandEvent& e) {
      comboBox1->SetSelection(comboBox3->GetSelection());
      comboBox2->SetSelection(comboBox3->GetSelection());
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxComboBox* comboBox1 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 10});
  wxComboBox* comboBox2 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 50}, wxDefaultSize, 0, nullptr, wxCB_READONLY);
#if defined(__WXMSW__)
  wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 90}, {110, 163}, 0, nullptr, wxCB_SIMPLE);
#else
  wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 90}, wxDefaultSize, 0, nullptr, wxCB_SIMPLE);
#endif
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
