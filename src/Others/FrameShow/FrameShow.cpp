#include <wx/wx.h>
#include <wx/statline.h>

namespace Examples {
  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Frame show example") {
      SetClientSize(320, 425);
      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        wxTheApp->Exit();
      });

      panel->SetSizerAndFit(boxSizer);
      boxSizer->Add(buttonNormal, 1, wxGROW|wxALL, 5);
      boxSizer->Add(buttonModeless, 1, wxGROW|wxALL, 5);
      boxSizer->Add(buttonStayOnTop, 1, wxGROW|wxALL, 5);
      boxSizer->Add(buttonModal, 1, wxGROW|wxALL, 5);
      
      buttonNormal->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxDialog* dialog = new wxDialog(nullptr, wxID_ANY, "dialog show normal", wxDefaultPosition, {250, 100});
        dialog->Show();
      });
      
      buttonModeless->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxDialog* dialog = new wxDialog(this, wxID_ANY, "dialog show modeless", wxDefaultPosition, {250, 100}, wxDEFAULT_DIALOG_STYLE|wxFRAME_FLOAT_ON_PARENT);
        dialog->Show();
      });
      
      buttonStayOnTop->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxDialog* dialog = new wxDialog(nullptr, wxID_ANY, "dialog stay on top", wxDefaultPosition, {250, 100}, wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP);
        dialog->Show();
      });

      buttonModal->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxDialog* dialog = new wxDialog(this, wxID_ANY, "dialog show modal", wxDefaultPosition, {250, 100});
        dialog->ShowModal();
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    wxButton* buttonNormal = new wxButton(panel, wxID_ANY, "Show normal", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonModeless = new wxButton(panel, wxID_ANY, "Show modeless", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonStayOnTop = new wxButton(panel, wxID_ANY, "Show stay on top", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonModal = new wxButton(panel, wxID_ANY, "Show modal", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
