#include <stdexcept>
#include <wx/wx.h>

using namespace std;

namespace Examples {
  class MainFrame : public wxFrame {
  public:
    MainFrame() : wxFrame {nullptr, wxID_ANY, "Application and assert example"} {
      buttonGenerateAssert->Bind(wxEVT_BUTTON, &MainFrame::GenerateAssert, this);

      buttonGenerateFail->Bind(wxEVT_BUTTON, &MainFrame::GenerateFail, this);
    }
    
  private:
    void GenerateAssert(wxCommandEvent& event) {
      auto index = 0;
      wxASSERT_MSG(index > 0, "Index must be greather than 0.");
    }
    
    void GenerateFail(wxCommandEvent& event) {
      wxFAIL;
    }

    wxPanel* panel = new wxPanel {this};
    wxButton* buttonGenerateAssert = new wxButton(panel, wxID_ANY, "Generate assert", {10, 10});
    wxButton* buttonGenerateFail = new wxButton(panel, wxID_ANY, "Generate fail", {10, 40});
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
