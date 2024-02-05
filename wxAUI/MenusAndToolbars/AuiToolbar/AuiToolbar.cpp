#include <wx/aui/auibar.h>
#include <wx/aui/framemanager.h>
#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/listbox.h>
#include <map>

using namespace std;

namespace AuiToolbarExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "AuiToolbar example"} {
      SetClientSize(640, 480);
      
      // On Windows the default size icon of toolbar is 16x16 and not 32x32...
      auto bitmapSize = wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? wxSize {16, 16} : wxDefaultSize;
      
      toolBar1->AddTool(wxID_NEW, "&New", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddTool(wxID_OPEN, "&Open...", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddTool(wxID_SAVE, "&Save", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddSeparator();
      toolBar1->AddTool(wxID_CUT, "Cu&t", wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddTool(wxID_COPY, "&Copy", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddTool(wxID_PASTE, "&Paste", wxArtProvider::GetBitmap(wxART_PASTE, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddSeparator();
      toolBar1->AddTool(wxID_PRINT, "&Print...", wxArtProvider::GetBitmap(wxART_PRINT, wxART_TOOLBAR, bitmapSize));
      toolBar1->AddSeparator();
      toolBar1->AddControl(choice);
      toolBar1->AddStretchSpacer();
      toolBar1->AddTool(wxID_ABOUT, "&About...", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR, bitmapSize));
      toolBar1->Realize();
      toolBar1->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static auto names = map<int, wxString> {{wxID_NEW, "New"}, {wxID_OPEN, "Open..."}, {wxID_SAVE, "Save"}, {wxID_EXIT, "Quit"}, {wxID_CUT, "Cut"}, {wxID_COPY, "Copy"}, {wxID_PASTE, "Paste"}, {wxID_PRINT, "Print..."}, {wxID_ABOUT, "About..."}, {wxID_ANY, "Any"}};
        auto iterator = names.find(event.GetId());
        listBox1->Append(iterator != names.end() ? iterator->second : "(Unknown)");
        if (event.GetId() == wxID_EXIT) Close();
      });
      
      toolBar2->AddTool(wxID_UNDO, "Undo", wxArtProvider::GetBitmap(wxART_UNDO, wxART_TOOLBAR, bitmapSize));
      toolBar2->AddTool(wxID_REDO, "Redo", wxArtProvider::GetBitmap(wxART_REDO, wxART_TOOLBAR, bitmapSize));
      auto select_all_tool = toolBar2->AddLabel(wxID_SELECTALL, "Select all");
      toolBar2->AddSeparator();
      toolBar2->AddControl(gauge);
      toolBar2->Realize();
      toolBar2->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static map<int, wxString> names = {{wxID_UNDO, "Undo..."}, {wxID_REDO, "Redo..."}, {wxID_SELECTALL, "Select all..."}, {wxID_ANY, "Any"}};
        if (names.find(event.GetId()) != names.end()) listBox1->Append(names[event.GetId()]);
        if (event.GetId() == wxID_EXIT) Close();
      });
      
      auiManager->AddPane(listBox1, wxAuiPaneInfo {}.Center().CaptionVisible(false).CloseButton(false));
      auiManager->AddPane(toolBar1, wxAuiPaneInfo {}.ToolbarPane().Top().Caption("Standard toolbar").CloseButton(false));
      auiManager->AddPane(toolBar2, wxAuiPaneInfo {}.ToolbarPane().Top().Caption("Extra toolbar").CloseButton(false).Row(1));
      auiManager->Update();
      
      gauge->SetValue(50);
      choice->Append(vector {"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
      choice->SetSelection(0);
      choice->Bind(wxEVT_CHOICE, [&](wxCommandEvent&) {listBox1->Append(wxString::Format("Choose item : %s", choice->GetStringSelection()));});
    }
    
  private:
    wxListBox* listBox1 = new wxListBox {this, wxID_ANY};
    wxAuiManager* auiManager = new wxAuiManager {this};
    wxAuiToolBar* toolBar1 = new wxAuiToolBar {this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER};
    wxAuiToolBar* toolBar2 = new wxAuiToolBar {this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_GRIPPER};
    wxChoice* choice = new wxChoice {toolBar1, wxID_ANY};
    wxGauge* gauge = new wxGauge {toolBar2, wxID_ANY, 100, wxDefaultPosition, {150, wxDefaultCoord}};
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(AuiToolbarExample::Application);

