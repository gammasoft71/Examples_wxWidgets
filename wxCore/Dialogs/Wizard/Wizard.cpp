#include <wx/wx.h>
#include <wx/wizard.h>

namespace WizardExample {
  class Frame : public wxFrame {
    class WizardPage1 : public wxWizardPage {
    public:
      explicit WizardPage1(wxWizard* parent) : wxWizardPage(parent) {}
 
      wxWizardPage* GetPrev() const override {return nullptr;}
      wxWizardPage* GetNext() const override {return next;}

      void SetNext(wxWizardPage* next) noexcept {this->next = next;}

    private:
      wxStaticText* label = new wxStaticText {this, wxID_ANY, "Wizard page 1...", {10, 10}};
      wxWizardPage* next = nullptr;
    };

    class WizardPage2 : public wxWizardPage {
    public:
      explicit WizardPage2(wxWizard* parent) : wxWizardPage(parent) {}
      
      wxWizardPage* GetPrev() const override {return prev;}
      wxWizardPage* GetNext() const override {return next;}
      
      void SetNext(wxWizardPage *next) noexcept {this->next = next;}
      void SetPrev(wxWizardPage *prev) noexcept {this->prev = prev;}

    private:
      wxStaticText* label = new wxStaticText {this, wxID_ANY, "Wizard page 2...", {10, 10}};
      wxWizardPage* next = nullptr;
      wxWizardPage* prev = nullptr;
    };

    class WizardPage3 : public wxWizardPage {
    public:
      explicit WizardPage3(wxWizard* parent) : wxWizardPage(parent) {}
      
      wxWizardPage* GetPrev() const override {return prev;}
      wxWizardPage* GetNext() const override {return nullptr;}
      
      void SetPrev(wxWizardPage *prev) noexcept {this->prev = prev;}
      
    private:
      wxStaticText* label = new wxStaticText {this, wxID_ANY, "Wizard page 3...", {10, 10}};
      wxWizardPage* prev = nullptr;
    };

  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Wizard example") {
      button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
        label->SetLabel("Wizard result = (none)");
        auto wizard = new wxWizard {this, wxID_ANY, "Wizard demo"};
        auto page1 = new WizardPage1 {wizard};
        auto page2 = new WizardPage2 {wizard};
        auto page3 = new WizardPage3 {wizard};
        page1->SetNext(page2);
        page2->SetNext(page3);
        page2->SetPrev(page1);
        page3->SetPrev(page2);
        auto result = wizard->RunWizard(page1);
        label->SetLabel(result ? "Wizard result = Finished" : "Wizard result = Cancel");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Wizard...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "Wizard result = (none)", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(WizardExample::Application);
