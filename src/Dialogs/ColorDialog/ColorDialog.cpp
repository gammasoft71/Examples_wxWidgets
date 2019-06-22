#include <wx/wx.h>
#include <wx/Colordlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ColorDialog example", wxDefaultPosition, wxSize(300, 300)) {
    this->button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
      wxColourData colorData;
      colorData.SetColour(this->GetBackgroundColour());
      wxColourDialog colorDialog(this, &colorData);
      if (colorDialog.ShowModal()) {
        this->SetBackgroundColour(colorDialog.GetColourData().GetColour());
        this->Refresh();
      }
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(this->panel, wxID_ANY, "Color...", wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
