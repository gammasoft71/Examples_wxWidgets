#include <wx/app.h>
#include <wx/artprov.h>
#include <wx/bmpbuttn.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/frame.h>
#include <wx/imaglist.h>
#include <wx/panel.h>
#include <wx/sysopt.h>
#include <wx/settings.h>
#include <wx/statbmp.h>

namespace ImageListExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ImageList example"} {
      wxInitAllImageHandlers();
      SetClientSize({300, 250});
      
      panel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        LoadImages();
      });

      picture->SetSize({150, 150});
      picture->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
      picture->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        LoadImages();
      });

      buttonBack->Enable(false);
      buttonBack->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex > 0) picture->SetBitmap(pictures->GetBitmap(--currentImageIndex));
        picture->SetSize({150, 150});
        buttonBack->Enable(currentImageIndex > 0);
        buttonForward->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      });

      buttonForward->Enable(false);
      buttonForward->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex < pictures->GetImageCount()) picture->SetBitmap(pictures->GetBitmap(++currentImageIndex));
        picture->SetSize({150, 150});
        buttonBack->Enable(currentImageIndex > 0);
        buttonForward->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      });

      Show();
      LoadImages();
    }

  private:
    void LoadImages() {
      auto openFileDialog = wxFileDialog {this, wxEmptyString, wxEmptyString, wxEmptyString, "All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff;*.xpm|Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|xpm Files|*.xpm", wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE};
      if (openFileDialog.ShowModal() == wxID_OK) {
        auto filenames = wxArrayString {};
        openFileDialog.GetFilenames(filenames);
        pictures->RemoveAll();
        for (auto filename : filenames)
          pictures->Add({wxImage {openFileDialog.GetDirectory() + wxFileName::GetPathSeparator() + filename}.Rescale(128, 128, wxIMAGE_QUALITY_HIGH)});
        currentImageIndex = 0;
        picture->SetBitmap(pictures->GetBitmap(currentImageIndex));
        picture->SetSize({150, 150});
        buttonBack->Enable(currentImageIndex > 0);
        buttonForward->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      }
    }
    
    int currentImageIndex = 0;
    wxPanel* panel = new wxPanel {this};
    wxImageList* pictures = new wxImageList {128, 128};
    wxStaticBitmap* picture = new wxStaticBitmap {panel, wxID_ANY, wxNullBitmap, {75, 25}, wxDefaultSize, wxBORDER_SUNKEN};
    wxBitmapButton* buttonBack = new wxBitmapButton {panel, wxID_UP, wxArtProvider::GetBitmap(wxART_GO_BACK, wxART_BUTTON), {75, 200}, {75, 25}};
    wxBitmapButton* buttonForward = new wxBitmapButton {panel, wxID_DOWN, wxArtProvider::GetBitmap(wxART_GO_FORWARD, wxART_BUTTON), {150, 200}, {75, 25}};
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
      return (new Frame);
    }
  };
}

wxIMPLEMENT_APP(ImageListExample::Application);
