#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, {300, 300}) {
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        comboBox1->Append(item);
      comboBox1->Select(0);
      comboBox1->Bind(wxEVT_COMBOBOX, [&](wxCommandEvent& e) {
        comboBox2->SetSelection(comboBox1->GetSelection());
        comboBox3->SetSelection(comboBox1->GetSelection());
      });

      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        comboBox2->Append(item);
      comboBox2->Select(0);
      comboBox2->Bind(wxEVT_COMBOBOX, [&](wxCommandEvent& e) {
        comboBox1->SetSelection(comboBox2->GetSelection());
        comboBox3->SetSelection(comboBox2->GetSelection());
      });

      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        comboBox3->Append(item);
      comboBox3->Select(0);
      comboBox3->Bind(wxEVT_COMBOBOX, [&](wxCommandEvent& e) {
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
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
