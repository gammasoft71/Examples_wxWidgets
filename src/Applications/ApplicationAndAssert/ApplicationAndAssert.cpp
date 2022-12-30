#undef NDEBUG
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
      wxASSERT_MSG(index > 0, "Index must be greater than 0.");
    }
    
    void GenerateFail(wxCommandEvent& event) {
      wxFAIL;
    }

    wxPanel* panel = new wxPanel {this};
    wxButton* buttonGenerateAssert = new wxButton(panel, wxID_ANY, "Generate assert", {10, 10});
    wxButton* buttonGenerateFail = new wxButton(panel, wxID_ANY, "Generate fail", {10, 40});
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new MainFrame)->Show();
      return true;
    }
    
  private:
    std::exception_ptr exceptionStored;
  };
}

wxIMPLEMENT_APP(Examples::Application);
