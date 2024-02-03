#include <vector>
#include <wx/artprov.h>
#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/imaglist.h>
#include <wx/sysopt.h>
#include <wx/settings.h>

using namespace std;

namespace ArtProviderExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ArtProvider example") {
      wxInitAllImageHandlers();
      SetClientSize(wxSize(300, 290));
      
      picture->SetSize(150, 150);
      picture->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));

      buttonPrevious->Enable(false);
      buttonPrevious->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (artIDsIndex > 0) --artIDsIndex;
        UpdateFrame();
      });

      buttonNext->Enable(false);
      buttonNext->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (artIDsIndex < artIDs.size()) ++artIDsIndex;
        UpdateFrame();
      });

      Show();
      UpdateFrame();
    }

  private:
    void UpdateFrame() {
      picture->SetScaleMode(wxStaticBitmap::Scale_None);
      picture->SetBitmap(wxArtProvider::GetBitmap(artIDs[artIDsIndex], wxART_OTHER, {128, 128}));
      picture->SetSize(150, 150);
      name->SetLabel(artIDs[artIDsIndex]);
      buttonPrevious->Enable(artIDsIndex > 0);
      buttonNext->Enable(artIDsIndex < artIDs.size() - 1);
    }
    
    size_t artIDsIndex = 0;
    vector<wxArtID> artIDs{wxART_ADD_BOOKMARK, wxART_DEL_BOOKMARK, wxART_HELP_SIDE_PANEL, wxART_HELP_SETTINGS, wxART_HELP_BOOK, wxART_HELP_FOLDER, wxART_HELP_PAGE, wxART_GO_BACK, wxART_GO_FORWARD, wxART_GO_UP, wxART_GO_DOWN, wxART_GO_TO_PARENT, wxART_GO_HOME, wxART_GOTO_FIRST, wxART_GOTO_LAST, wxART_FILE_OPEN, wxART_FILE_SAVE, wxART_FILE_SAVE_AS, wxART_PRINT, wxART_HELP, wxART_TIP, wxART_REPORT_VIEW, wxART_LIST_VIEW, wxART_NEW_DIR, wxART_HARDDISK, wxART_FLOPPY, wxART_CDROM, wxART_REMOVABLE, wxART_FOLDER, wxART_FOLDER_OPEN, wxART_GO_DIR_UP, wxART_EXECUTABLE_FILE, wxART_NORMAL_FILE, wxART_TICK_MARK, wxART_CROSS_MARK, wxART_ERROR, wxART_QUESTION, wxART_WARNING, wxART_INFORMATION, wxART_MISSING_IMAGE, wxART_COPY, wxART_CUT, wxART_PASTE, wxART_DELETE, wxART_NEW, wxART_UNDO, wxART_REDO, wxART_PLUS, wxART_MINUS, wxART_CLOSE, wxART_QUIT, wxART_FIND, wxART_FIND_AND_REPLACE, wxART_FULL_SCREEN, wxART_EDIT};
    wxPanel* panel = new wxPanel {this};
    wxStaticBitmap* picture = new wxStaticBitmap(panel, wxID_ANY, wxNullBitmap, {75, 25}, wxDefaultSize, wxBORDER_SUNKEN);
    wxStaticText* name = new wxStaticText(panel, wxID_ANY, wxEmptyString, {75, 200}, {150, wxDefaultCoord}, wxALIGN_CENTRE_HORIZONTAL);
    wxButton* buttonPrevious = new wxButton(panel, wxID_ANY, "&<", {75, 240}, {75, 25}, wxBORDER_SIMPLE);
    wxButton* buttonNext = new wxButton(panel, wxID_ANY, "&>", {150, 240}, {75, 25}, wxBORDER_SIMPLE);
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
      new Frame();
      return true;
    }
  };
}

wxIMPLEMENT_APP(ArtProviderExample::Application);
