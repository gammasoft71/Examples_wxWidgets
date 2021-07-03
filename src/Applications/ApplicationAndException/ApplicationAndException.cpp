#include <stdexcept>
#include <wx/wx.h>

using namespace std;

namespace Examples {
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
    wxButton* buttonGenerateHandledException = new wxButton(panel, wxID_ANY, "Generate handled exception", {10, 10});
    wxButton* buttonGenerateException = new wxButton(panel, wxID_ANY, "Generate exception", {10, 40});
    wxButton* buttonGenerateUnknownException = new wxButton(panel, wxID_ANY, "Generate unknown exception", {10, 70});
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
        (new MainFrame)->Show();
      } catch(const exception& e) {
        ShowExceptiionError(e);
        return false;
      } catch(...) {
        ShowExceptiionError();
        return false;
      }
      return true;
    }

    static int ShowExceptiionError(const std::exception& e) {
      return wxMessageBox(wxString::Format("Unhandled exception occured in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n%s", e.what()), "Exception occured", wxOK|wxCANCEL|wxICON_ERROR);
    }
    
    static int ShowExceptiionError() {
      return wxMessageBox("Unhandled exception occured in your application. If you click\nOK, the application will ignore this error and attempt to continue.\nIf you click Cancel, the application will close immediately.\n\n(Unknown exception)", "Unknown exception occured", wxOK|wxCANCEL|wxICON_ERROR);
    }

  private:
    std::exception_ptr exceptionStored;
  };
}

wxIMPLEMENT_APP(Examples::Application);
