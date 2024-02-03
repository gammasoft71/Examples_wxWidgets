#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ComboBoxExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example") {
      SetClientSize(400, 270);
      comboBox1->Append(wxArrayString {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
      comboBox1->Select(0);
      comboBox1->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxSelectionChanged, this);

      comboBox2->Append(wxArrayString {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
      comboBox2->Select(0);
      comboBox2->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxSelectionChanged, this);

      comboBox3->Append(wxArrayString {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
      comboBox3->Select(0);
      comboBox3->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxSelectionChanged, this);
    }

  private:
    void OnComboBoxSelectionChanged(wxCommandEvent& e) {
      comboBox1->SetSelection(static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
      comboBox2->SetSelection(static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
      comboBox3->SetSelection(static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
    }
    wxPanel* panel = new wxPanel {this};
    wxComboBox* comboBox1 = new wxComboBox {panel, wxID_ANY, wxEmptyString, {10, 10}};
    wxComboBox* comboBox2 = new wxComboBox {panel, wxID_ANY, wxEmptyString, {10, 50}, wxDefaultSize, 0, nullptr, wxCB_READONLY};
    wxComboBox* comboBox3 = new wxComboBox {panel, wxID_ANY, wxEmptyString, {10, 90}, wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? wxSize(110, 163) : wxDefaultSize, 0, nullptr, wxCB_SIMPLE};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ComboBoxExample::Application);
