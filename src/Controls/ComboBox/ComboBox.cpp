#include <wx/app.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ComboBoxExample {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "ComboBox example") {
    SetClientSize(400, 270);
    for (int i = 1; i <= 10; ++i) {
      comboBox1->Append("item " + std::to_string(i));
    }
    comboBox1->Select(0);
    comboBox1->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);

    for (int i = 1; i <= 10; ++i) {
      comboBox2->Append("item " + std::to_string(i));
    }
    comboBox2->Select(0);
    comboBox2->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);
    for (int i = 1; i <= 10; ++i) {
      comboBox3->Append("item " + std::to_string(i));
    }
    comboBox3->Select(0);
    comboBox3->Bind(wxEVT_COMBOBOX, &Frame::OnComboBoxClick, this);
  }

private:
  void OnComboBoxClick(wxCommandEvent &e) {
    comboBox1->SetSelection(
        static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
    comboBox2->SetSelection(
        static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
    comboBox3->SetSelection(
        static_cast<wxComboBox *>(e.GetEventObject())->GetSelection());
  }
  wxPanel *panel = new wxPanel(this);
  wxComboBox *comboBox1 =
      new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 10});
  wxComboBox *comboBox2 =
      new wxComboBox(panel, wxID_ANY, wxEmptyString, {10, 50}, wxDefaultSize, 0,
                     nullptr, wxCB_READONLY);
  wxComboBox *comboBox3 = new wxComboBox(
      panel, wxID_ANY, wxEmptyString, {10, 90},
      wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows"
          ? wxSize(110, 163)
          : wxDefaultSize,
      0, nullptr, wxCB_SIMPLE);
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
} // namespace ComboBoxExample

wxIMPLEMENT_APP(ComboBoxExample::Application);
