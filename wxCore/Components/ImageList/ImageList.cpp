#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/imaglist.h>
#include <wx/sysopt.h>
#include <wx/settings.h>
#include <wx/artprov.h>

namespace ImageListExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ImageList example") {
      wxInitAllImageHandlers();
      SetClientSize(wxSize(300, 250));
      
      panel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        LoadImages();
      });

      picture->SetSize(150, 150);
      picture->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
      picture->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& event) {
        LoadImages();
      });

      buttonUp->Enable(false);
      buttonUp->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex > 0) picture->SetBitmap(pictures->GetBitmap(--currentImageIndex));
        picture->SetSize(150, 150);
        buttonUp->Enable(currentImageIndex > 0);
        buttonDown->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      });

      buttonDown->Enable(false);
      buttonDown->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex < pictures->GetImageCount()) picture->SetBitmap(pictures->GetBitmap(++currentImageIndex));
        picture->SetSize(150, 150);
        buttonUp->Enable(currentImageIndex > 0);
        buttonDown->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      });

      Show();
      LoadImages();
    }

  private:
    void LoadImages() {
      wxFileDialog openFileDialog(this, wxEmptyString, wxEmptyString, wxEmptyString, "All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff;*.xpm|Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|xpm Files|*.xpm", wxFD_OPEN|wxFD_FILE_MUST_EXIST|wxFD_MULTIPLE);
      if (openFileDialog.ShowModal() == wxID_OK) {
        wxArrayString filenames;
        openFileDialog.GetFilenames(filenames);
        pictures->RemoveAll();
        for (auto filename : filenames) {
          auto image = wxImage(openFileDialog.GetDirectory() + wxFileName::GetPathSeparator() + filename);
          pictures->Add(wxBitmap(image.Rescale(128, 128, wxIMAGE_QUALITY_HIGH)));
        }
        currentImageIndex = 0;
        picture->SetBitmap(pictures->GetBitmap(currentImageIndex));
        picture->SetSize(150, 150);
        buttonUp->Enable(currentImageIndex > 0);
        buttonDown->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      }
    }
    
    int currentImageIndex = 0;
    wxPanel* panel = new wxPanel {this};
    wxImageList* pictures = new wxImageList(128, 128);
    wxStaticBitmap* picture = new wxStaticBitmap(panel, wxID_ANY, wxNullBitmap, {75, 25}, wxDefaultSize, wxBORDER_SUNKEN);
    wxBitmapButton* buttonUp = new wxBitmapButton(panel, wxID_UP, wxArtProvider::GetBitmap(wxART_GO_UP, wxART_BUTTON), {75, 200}, {75, 25});
    wxBitmapButton* buttonDown = new wxBitmapButton(panel, wxID_DOWN, wxArtProvider::GetBitmap(wxART_GO_DOWN, wxART_BUTTON), {150, 200}, {75, 25});
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
      new Frame;
      return true;
    }
  };
}

wxIMPLEMENT_APP(ImageListExample::Application);
