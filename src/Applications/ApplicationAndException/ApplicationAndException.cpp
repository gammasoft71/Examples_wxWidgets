#include <stdexcept>
#include <wx/wx.h>

using namespace std;

namespace Examples {
  class MainFrame : public wxFrame {
  public:
    MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
      // uncomment to throw exception
      //throw overflow_error("Creattion object error");

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
        wxFAIL_MSG_AT(e.what(), __FILE__, __LINE__, __func__);
      } catch(...) {
        wxFAIL_MSG_AT("Unknown exception occured", __FILE__, __LINE__, __func__);
      }
      return true;
    }

    bool OnInit() override {
      try {
        (new MainFrame)->Show();
      } catch(const exception& e) {
        wxFAIL_MSG_AT(e.what(), __FILE__, __LINE__, __func__);
      } catch(...) {
        wxFAIL_MSG_AT("Unknown exception occured", __FILE__, __LINE__, __func__);
      }
      return true;
    }
    
  private:
    std::exception_ptr exceptionStored;
  };
}

wxIMPLEMENT_APP(Examples::Application);
