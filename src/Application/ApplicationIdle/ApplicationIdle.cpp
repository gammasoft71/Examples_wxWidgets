#include <chrono>
#include <wx/wx.h>

using namespace std::chrono_literals;

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 300)) {}
  
  void OnApplicationIdle() {
    this->SetLabel(wxString::Format("%d", ++this->counter));
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  int counter = 0;
};

class Application : public wxApp {
  bool OnInit() override {return (this->form = new Form())->Show();}
 
  bool ProcessIdle() override {
    if (!form->IsVisible()) return this->wxApp::ProcessIdle();

    static std::chrono::high_resolution_clock::time_point lastIdleTime;
    std::chrono::high_resolution_clock::duration elapsedTime = std::chrono::high_resolution_clock::now() - lastIdleTime;
    if (elapsedTime >= 100ms) {
      form->OnApplicationIdle();
      lastIdleTime = std::chrono::high_resolution_clock::now();
    }

    this->wxApp::ProcessIdle();
    return true;
    ;
  }

  Form* form = nullptr;
};

wxIMPLEMENT_APP(Application);
