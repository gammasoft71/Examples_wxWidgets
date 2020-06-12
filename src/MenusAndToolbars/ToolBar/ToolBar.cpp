#include <map>
#include <wx/wx.h>
#include <wx/artprov.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Toolbar example") {
      SetClientSize(640, 480);

#if defined(__WXOSX__)
      wxSize bitmapSize(-1, -1);
#else
      wxSize bitmapSize(16, 16);
#endif
      toolBar->SetToolBitmapSize(bitmapSize);
      toolBar->AddTool(wxID_NEW, "&New", wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_OPEN, "&Open...", wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_SAVE, "&Save", wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR, bitmapSize));
      toolBar->AddSeparator();
      toolBar->AddTool(wxID_CUT, "Cu&t", wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_COPY, "&Copy", wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR, bitmapSize));
      toolBar->AddTool(wxID_PASTE, "&Paste", wxArtProvider::GetBitmap(wxART_PASTE, wxART_TOOLBAR, bitmapSize));
      toolBar->AddSeparator();
      toolBar->AddTool(wxID_PRINT, "&Print...", wxArtProvider::GetBitmap(wxART_PRINT, wxART_TOOLBAR, bitmapSize));
      toolBar->AddSeparator();
      toolBar->AddControl(choice);
      toolBar->AddStretchableSpace();
      toolBar->AddTool(wxID_ABOUT, "&About...", wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR, bitmapSize));

      SetToolBar(toolBar);
      toolBar->Realize();
      toolBar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
        static std::map<int, std::string> names = {{wxID_NEW, "New"}, {wxID_OPEN, "Open..."}, {wxID_SAVE, "Save"}, {wxID_EXIT, "Quit"}, {wxID_CUT, "Cut"}, {wxID_COPY, "Copy"}, {wxID_PASTE, "Paste"}, {wxID_PRINT, "Print..."}, {wxID_ABOUT, "About..."}, {wxID_ANY, "Any"}};
        listBox1->Append(names.find(event.GetId()) != names.end() ? names[event.GetId()] : "Unknown");
        if (event.GetId() == wxID_EXIT) Close();
      });
      
      for (auto item : {"item 1", "item 2", "item 3", "item 4", "item 5", "item 6", "item 7", "item 8", "item 9", "item 10"})
        choice->Append(item);
      choice->SetSelection(0);
      choice->Bind(wxEVT_CHOICE, [&](wxCommandEvent& e) {
        listBox1->Append(wxString::Format("Choose item : %s", choice->GetStringSelection()));
      });
      
    }

  private:
    wxListBox* listBox1 = new wxListBox(this, wxID_ANY, {10, 10});
    wxToolBar* toolBar = new wxToolBar(this, wxID_ANY);
    wxChoice* choice = new wxChoice(toolBar, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
