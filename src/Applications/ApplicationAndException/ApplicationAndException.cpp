#include <stdexcept>
#include <wx/wx.h>

using namespace std;

namespace Examples {
  class MainFrame : public wxFrame {
  public:
    MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
      // uncomment to throw exception
      //throw overflow_error("Creattion object error");

      buttonGenerateHandledException->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        try {
          throw invalid_argument("Not a valid argument");
        } catch (const exception& e) {
          // Do something...
        }
      });
      
      buttonGenerateException->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        throw invalid_argument("Not a valid argument");
      });
      
      buttonGenerateUnknownException->Bind(wxEVT_BUTTON, [](wxCommandEvent& event) {
        throw "throw unknown type exception";
      });
    }
    
  private:
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
        wxMessageBox(wxString::Format("Message: %s\n", e.what()), "Exception occured", wxOK);
      } catch(...) {
        wxMessageBox("Message: (none)", "Unknown exception occured", wxOK);
      }
      return false; // return true to continue...
    }

    bool OnInit() override {
      try {
        (new MainFrame)->Show();
        return true;
      } catch(const exception& e) {
        wxMessageBox(wxString::Format("Message: %s\n", e.what()), "Exception occured", wxOK);
      } catch(...) {
        wxMessageBox("Message: (none)", "Unknown exception occured", wxOK);
      }
    }
    
  private:
    std::exception_ptr exceptionStored;
  };
}

wxIMPLEMENT_APP(Examples::Application);
