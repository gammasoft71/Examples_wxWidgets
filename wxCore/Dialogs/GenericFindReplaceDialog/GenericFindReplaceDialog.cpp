#include <wx/wx.h>
#include <wx/fdrepdlg.h>
#include <wx/generic/fdrepdlg.h>

namespace GenericFindReplaceDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "GenericFindReplaceDialog example"} {
      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
#if !defined(__WXMSW__)
        findReplaceData.SetFlags(wxFR_WHOLEWORD | wxFR_MATCHCASE | wxFR_DOWN);
        findReplaceData.SetFindString("Gammasoft");
        findReplaceData.SetReplaceString("Gammasoft71");
        findReplaceDialog = new wxGenericFindReplaceDialog {this, &findReplaceData, "Find and replace", wxFR_REPLACEDIALOG};
        findReplaceDialog->Bind(wxEVT_FIND_CLOSE, [&](wxFindDialogEvent& event) {
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
#else
        auto messageDialog = wxMessageDialog {this, "Does not work on Windows!", "Error", wxOK};
        messageDialog.ShowModal();
#endif
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Find...", {10, 10}};
    wxFindReplaceData findReplaceData;
    wxGenericFindReplaceDialog* findReplaceDialog;
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(GenericFindReplaceDialogExample::Application);

