#include "ShellExecute.h"
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <wx/process.h>
#include <wx/wx.h>

using namespace std;
using namespace std::filesystem;

namespace ShellExecuteExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Shell execute example") {
      SetClientSize(300, 450);
      Bind(wxEVT_CLOSE_WINDOW, [&](wxCloseEvent& event) {
        wxTheApp->Exit();
      });

      panel->SetSizerAndFit(boxSizer);
      boxSizer->Add(buttonWeb, 1, wxGROW);
      boxSizer->Add(buttonWriteMail, 1, wxGROW);
      boxSizer->Add(buttonOpenHomeFolder, 1, wxGROW);
      boxSizer->Add(buttonOpenReadmeTxtFile, 1, wxGROW);
      boxSizer->Add(buttonOpenCalculator, 1, wxGROW);

      buttonWeb->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxShellExecute("https://gammasoft71.wixsite.com/gammasoft");
      });
      
      buttonWriteMail->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxShellExecute("mailto:gammasoft71@gmail.com");
      });
      
      buttonOpenHomeFolder->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        wxShellExecute(wxGetHomeDir());
      });

      buttonOpenReadmeTxtFile->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        ofstream file(temp_directory_path()/"Readme.txt");
        file << "Tests open file \"Readme.txt\" with wxShellExecute method." << endl;
        file.close();
        wxShellExecute((temp_directory_path()/"Readme.txt").string());
      });

      buttonOpenCalculator->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") wxShellExecute("calc.exe");
        else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") wxShellExecute("/System/Applications/Calculator.app");
        else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Unix") wxShellExecute("gnome-calculator");
        else throw invalid_argument("Calculator not found.");
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxBoxSizer* boxSizer = new wxBoxSizer(wxVERTICAL);
    wxButton* buttonWeb = new wxButton(panel, wxID_ANY, "Open Gammasoft website...", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonWriteMail = new wxButton(panel, wxID_ANY, "Write mail...", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonOpenHomeFolder = new wxButton(panel, wxID_ANY, "Open home folder...", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonOpenReadmeTxtFile = new wxButton(panel, wxID_ANY, "Open Readme.txt file...", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
    wxButton* buttonOpenCalculator = new wxButton(panel, wxID_ANY, "Open Calculator...", wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE);
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ShellExecuteExample::Application);
