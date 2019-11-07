#include <wx/wx.h>
#include <wx/fdrepdlg.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ColorDialog example", wxDefaultPosition, wxSize(300, 300)) {
    button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      findReplaceData.SetFlags(wxFR_WHOLEWORD | wxFR_MATCHCASE | wxFR_DOWN);
      findReplaceData.SetFindString("Gammasoft");
      findReplaceData.SetReplaceString("Gammasoft71");
      findReplaceDialog = new wxFindReplaceDialog(this, &findReplaceData, "Find and replace", wxFR_REPLACEDIALOG);
      findReplaceDialog->Bind(wxEVT_FIND_CLOSE, [this](wxFindDialogEvent& event) {
        findReplaceDialog->Hide();
        findReplaceDialog->Destroy();
      });
      findReplaceDialog->Bind(wxEVT_FIND, [](wxFindDialogEvent& event) {
        wxMessageOutputDebug().Printf("Find {%s}", event.GetFindString());
      });
      findReplaceDialog->Bind(wxEVT_FIND_NEXT, [](wxFindDialogEvent& event) {
        wxMessageOutputDebug().Printf("Find next {%s}", event.GetFindString());
      });
      findReplaceDialog->Bind(wxEVT_FIND_REPLACE, [](wxFindDialogEvent& event) {
        wxMessageOutputDebug().Printf("Find and Replace {%s} by {%s}", event.GetFindString(), event.GetReplaceString());
      });
      findReplaceDialog->Bind(wxEVT_FIND_REPLACE_ALL, [](wxFindDialogEvent& event) {
        wxMessageOutputDebug().Printf("Find and Replace all {%s} by {%s}", event.GetFindString(), event.GetReplaceString());
      });

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
