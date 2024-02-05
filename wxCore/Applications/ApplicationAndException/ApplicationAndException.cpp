#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>

using namespace std;

namespace ApplicationAndExceptionExample {
  class MainFrame : public wxFrame {
  public:
    MainFrame() : wxFrame {nullptr, wxID_ANY, "Application and exception example"} {
      // uncomment to throw exception
      //throw overflow_error("Creation object error");

      buttonGenerateHandledException->Bind(wxEVT_BUTTON, &MainFrame::GenerateHandledException, this);
      
      buttonGenerateException->Bind(wxEVT_BUTTON, &MainFrame::GenerateException, this);
      
      buttonGenerateUnknownException->Bind(wxEVT_BUTTON, &MainFrame::GenerateUnknownException, this);
    }
    
  private:
    void GenerateHandledException(wxCommandEvent& event) {
      try {
        throw invalid_argument("Exception handled generated");
      } catch (const exception& e) {
        wxMessageBox(e.what(), "Exception handled", wxOK);
      }
    }
    void GenerateException(wxCommandEvent& event) {throw invalid_argument("Exception generated");}
    void GenerateUnknownException(wxCommandEvent& event) {throw "Unknown exception generated";}

    wxPanel* panel = new wxPanel {this};
    wxButton* buttonGenerateHandledException = new wxButton {panel, wxID_ANY, "Generate handled exception", {10, 10}};
    wxButton* buttonGenerateException = new wxButton {panel, wxID_ANY, "Generate exception", {10, 40}};
    wxButton* buttonGenerateUnknownException = new wxButton {panel, wxID_ANY, "Generate unknown exception", {10, 70}};
  };
  
  class Application : public wxApp {
    bool OnExceptionInMainLoop() override {
      try {
        throw;
      } catch(const exception& e) {
        return ShowExceptiionError(e) == wxOK;
      } catch(...) {
        return ShowExceptiionError() == wxOK;
      }
      return true;
    }

    bool OnInit() override {
      try {
        return (new MainFrame)->Show();
      } catch(const exception& e) {
        ShowExceptiionError(e);
      } catch(...) {
        ShowExceptiionError();
      }
      return false;
    }

    static int ShowExceptiionError(const exception& e) {
      return wxMessageBox(wxString::Format("Unhandled exception occurred in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n%s", e.what()), "Exception occurred", wxOK|wxCANCEL|wxICON_ERROR);
    }
    
    static int ShowExceptiionError() {
      return wxMessageBox("Unhandled exception occurred in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n(Unknown exception)", "Unknown exception occurred", wxOK|wxCANCEL|wxICON_ERROR);
    }

  private:
    exception_ptr exceptionStored;
  };
}

wxIMPLEMENT_APP(ApplicationAndExceptionExample::Application);
