#include <chrono>
#include <wx/wx.h>

using namespace std::chrono_literals;

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(300, 300)) {
    this->Show();
  }
  
  void OnApplicationIdle() {
    this->SetLabel(wxString::Format("%d", ++this->counter));
  }
  
private:
  int counter = 0;
};

class Application : public wxApp {
public:
  bool OnInit() override {this->form = new Form(); return true;}
  bool ProcessIdle() override {
    static std::chrono::high_resolution_clock::time_point lastIdleTime;
    std::chrono::high_resolution_clock::duration elapsedTime = std::chrono::high_resolution_clock::now() - lastIdleTime;
    if (elapsedTime >= 100ms) {
      form->OnApplicationIdle();
      lastIdleTime = std::chrono::high_resolution_clock::now();
    }
    return true;
  }
  
private:
  Form* form;
};

wxIMPLEMENT_APP(Application);
