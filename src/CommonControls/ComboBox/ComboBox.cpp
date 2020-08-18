#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/platinfo.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example", wxDefaultPosition, {300, 300}) {
      comboBox1->Append({"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      comboBox1->Select(0);
      comboBox1->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);

      comboBox2->Append({"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      comboBox2->Select(0);
      comboBox2->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);

      comboBox3->Append({"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"});
      comboBox3->Select(0);
      comboBox3->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);
      
      auto name = wxPlatformInfo::Get().GetOperatingSystemFamilyName();
      std::cout << name << std::endl;
    }
    
  private:
    void OnComboBoxClick(wxCommandEvent& e) {
      comboBox1->SetSelection(static_cast<wxComboBox*>(e.GetEventObject())->GetSelection());
      comboBox2->SetSelection(static_cast<wxComboBox*>(e.GetEventObject())->GetSelection());
      comboBox3->SetSelection(static_cast<wxComboBox*>(e.GetEventObject())->GetSelection());
    }
    wxPanel* panel = new wxPanel(this);
    wxComboBox* comboBox1 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 10});
    wxComboBox* comboBox2 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 50}, wxDefaultSize, 0, nullptr, wxCB_READONLY);
    wxComboBox* comboBox3 = new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 90}, wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? wxSize(110, 163) : wxDefaultSize, 0, nullptr, wxCB_SIMPLE);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
