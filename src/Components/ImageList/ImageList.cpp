#include <wx/wx.h>
#include <wx/filename.h>
#include <wx/imaglist.h>
#include <wx/settings.h>

namespace Examples {
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

      buttonPrevious->Enable(false);
      buttonPrevious->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex > 0) picture->SetBitmap(pictures->GetBitmap(--currentImageIndex));
        picture->SetSize(150, 150);
        buttonPrevious->Enable(currentImageIndex > 0);
        buttonNext->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      });

      buttonNext->Enable(false);
      buttonNext->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        if (currentImageIndex < pictures->GetImageCount()) picture->SetBitmap(pictures->GetBitmap(++currentImageIndex));
        picture->SetSize(150, 150);
        buttonPrevious->Enable(currentImageIndex > 0);
        buttonNext->Enable(currentImageIndex < pictures->GetImageCount() - 1);
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
          pictures->Add(wxBitmap(image.Scale(128, 128)));
        }
        currentImageIndex = 0;
        picture->SetBitmap(pictures->GetBitmap(currentImageIndex));
        picture->SetSize(150, 150);
        buttonPrevious->Enable(currentImageIndex > 0);
        buttonNext->Enable(currentImageIndex < pictures->GetImageCount() - 1);
      }
    }
    
    int currentImageIndex = 0;
    wxPanel* panel = new wxPanel(this);
    wxImageList* pictures = new wxImageList(128, 128);
    wxStaticBitmap* picture = new wxStaticBitmap(panel, wxID_ANY, wxNullBitmap, {75, 25}, wxDefaultSize, wxBORDER_SUNKEN);
    wxButton* buttonPrevious = new wxButton(panel, wxID_ANY, "&<", {75, 200}, {75, 25});
    wxButton* buttonNext = new wxButton(panel, wxID_ANY, "&>", {150, 200}, {75, 25});
  };

  class Application : public wxApp {
    bool OnInit() override {
      new Frame();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
