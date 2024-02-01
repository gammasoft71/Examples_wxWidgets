#include <wx/wx.h>
#include <wx/wizard.h>

namespace WizardExample {
  class Frame : public wxFrame {
    class WizardPage2 : public wxWizardPage {
    public:
      WizardPage2(wxWizard* parent, wxWizardPage* previousPage) : wxWizardPage(parent), previousPage(previousPage) {}
      wxWizardPage* GetNext() const override {return nullptr;}
      wxWizardPage* GetPrev() const override {return previousPage;}
      
    private:
      wxWizardPage* previousPage = nullptr;
      wxStaticText* label = new wxStaticText(this, wxID_ANY, "Wizard page 2...", {10, 10});
    };
    
    class WizardPage1 : public wxWizardPage {
    public:
      WizardPage1(wxWizard* parent) : wxWizardPage(parent), parent(parent) {}
      wxWizardPage* GetNext() const override {return new WizardPage2(parent, const_cast<WizardPage1*>(this));}
      wxWizardPage* GetPrev() const override {return nullptr;}
      
    private:
      wxWizard* parent = nullptr;
      wxStaticText* label = new wxStaticText(this, wxID_ANY, "Wizard page 1...", {10, 10});
    };
    
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Wizard example") {
      button->Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
        label->SetLabel("Wizard result = (none)");
        wxWizard wizard(this, wxID_ANY, "Wizard demo");
        WizardPage1 page1(&wizard);
        auto result = wizard.RunWizard(&page1);
        label->SetLabel(result ? "Wizard result = Finished" : "Wizard result = Cancel");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxButton* button = new wxButton(panel, wxID_ANY, "Wizard...", {10, 10});
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "Wizard result = (none)", {10, 50});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(WizardExample::Application);
