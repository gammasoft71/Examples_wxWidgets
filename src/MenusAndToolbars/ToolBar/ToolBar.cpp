#include <map>
#include <wx/wx.h>
#include <wx/artprov.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Toolbar example") {
      SetClientSize(820, 500);
      
      // On Windows the default size icon of toolbar is 16x16, on macOS is 32x32 and on gtk is 24x24...
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows")
        bitmapSize = wxSize(16, 16);
      else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh")
        bitmapSize = wxSize(32, 32);
      else
        bitmapSize = wxSize(24, 24);
      toolBar->AddTool(wxID_NEW, "&New", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_OPEN, "&Open...", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_SAVE, "&Save", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_PRINT, "&Print...", wxArtProvider::GetBitmap(wxART_PRINT, wxART_TOOLBAR, bitmapSize));
      toolBar->AddSeparator();
      toolBar->AddTool(wxID_CUT, "Cu&t", wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_COPY, "&Copy", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_PASTE, "&Paste", wxArtProvider::GetBitmap(wxART_PASTE, wxART_TOOLBAR, bitmapSize));
      toolBar->AddSeparator();
      toolBar->AddControl(choice, "Items");
      toolBar->AddStretchableSpace();
      /// Does not works on macOS : No DropDown menu supported !
      toolBar->AddTool(wxID_HELP, "&Help", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR, bitmapSize), wxEmptyString, wxITEM_DROPDOWN);
      toolBar->SetDropdownMenu(wxID_HELP, menuHelp);
      
      SetToolBar(toolBar);
      toolBar->Realize();
      toolBar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static std::map<int, std::string> names = {{wxID_NEW, "New"}, {wxID_OPEN, "Open..."}, {wxID_SAVE, "Save"}, {wxID_EXIT, "Quit"}, {wxID_CUT, "Cut"}, {wxID_COPY, "Copy"}, {wxID_PASTE, "Paste"}, {wxID_PRINT, "Print..."}, {wxID_HELP, "Help"}, {wxID_HELP_CONTEXT, "Help context"}, {wxID_HELP_INDEX, "Help index"}, {wxID_HELP_SEARCH, "Help search"}, {wxID_ABOUT, "About..."}, {wxID_ANY, "Any"}};
        listBox1->Append(wxString::Format("%s clicked", names.find(event.GetId()) != names.end() ? names[event.GetId()] : "Unknown"));
        listBox1->Select(listBox1->GetCount() - 1);
        if (event.GetId() == wxID_EXIT) Close();
      });
      
      toolBar->Bind(wxEVT_TOOL_DROPDOWN, [&](wxCommandEvent& event) {
        listBox1->Append(wxString::Format("DropDown clicked"));
      });

      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        choice->Append(item);
      choice->SetSelection(0);
      choice->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        listBox1->Append(wxString::Format("Choose item : %s", choice->GetStringSelection()));
        listBox1->Select(listBox1->GetCount() - 1);
      });
      
      menuHelp->Append(wxID_HELP_CONTEXT, "Context");
      menuHelp->Append(wxID_HELP_INDEX, "Index");
      menuHelp->Append(wxID_HELP_SEARCH, "Search");
      menuHelp->AppendSeparator();
      menuHelp->Append(wxID_ABOUT, "About");
    }
    
  private:
    wxSize bitmapSize {24, 24};
    wxListBox* listBox1 = new wxListBox(this, wxID_ANY);
    wxToolBar* toolBar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL);
    wxChoice* choice = new wxChoice(toolBar, wxID_ANY);
    wxMenu* menuHelp = new wxMenu();
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
