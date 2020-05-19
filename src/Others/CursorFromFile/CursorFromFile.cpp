#include <wx/app.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/sizer.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "CursorFromFile example") {
      boxSizer->Add(buttonOpen, 0, wxGROW|wxTOP|wxWEST|wxEAST, 10);
      boxSizer->Add(testZone, 1, wxGROW|wxALL, 10);
      SetSizerAndFit(boxSizer);
      
      buttonOpen->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxFileDialog openFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, "Cursor Files (*.cur;*.ani)|*.cur;*.ani|All Files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        openFileDialog.SetFilterIndex(0);
        if (openFileDialog.ShowModal() == wxID_OK) {
          testZone->SetCursor(wxCursor(openFileDialog.GetPath()));
        }
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* buttonOpen = new wxButton(this, wxID_ANY, "Choose cursor");
    wxPanel* testZone = new wxPanel(this, wxID_ANY, wxDefaultPosition, {150, 200}, wxBORDER_SUNKEN);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
