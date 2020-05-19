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
      boxSizer->Add(buttonOpenCursor, 0, wxALIGN_CENTER|wxTOP|wxBOTTOM|wxLEFT, 10);
      boxSizer->Add(testZone, 1, wxGROW|wxALL, 10);
      panel->SetSizerAndFit(boxSizer);
      
      buttonOpenCursor->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxFileDialog openFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, "Cursor Files (*.cur;*.ani)|*.cur;*.ani|All Files (*.*)|*.*", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
        openFileDialog.SetFilterIndex(0);
        if (openFileDialog.ShowModal() == wxID_OK)
          testZone->SetCursor(wxCursor(openFileDialog.GetPath(), openFileDialog.GetPath().EndsWith(".ani") ? wxBITMAP_TYPE_ANI : wxBITMAP_TYPE_CUR));
      });

      testZone->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* buttonOpenCursor = new wxButton(panel, wxID_ANY, "Open cursor");
    wxPanel* testZone = new wxPanel(panel, wxID_ANY, wxDefaultPosition, {150, 200}, wxBORDER_SUNKEN);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
