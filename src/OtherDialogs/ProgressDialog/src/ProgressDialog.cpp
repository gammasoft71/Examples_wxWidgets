#include <wx/wx.h>
#include <wx/fdrepdlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ColorDialog example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      findReplaceData.SetFindString("Gammasoft");
      findReplaceData.SetReplaceString("Gammasoft71");
      findReplaceDialog = new wxFindReplaceDialog(this, &findReplaceData, "Find and replace", wxFR_REPLACEDIALOG);
      findReplaceDialog->Show();
    });
  }

private:
  wxPanel* panel = new wxPanel(this);
  wxButton* button = new wxButton(panel, wxID_ANY, "Find...", wxPoint(10, 10));
  wxFindReplaceData findReplaceData;
  wxFindReplaceDialog* findReplaceDialog;
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
