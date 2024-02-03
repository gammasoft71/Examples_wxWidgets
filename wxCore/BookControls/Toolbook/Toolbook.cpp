#include <wx/wx.h>
#include <wx/toolbook.h>

namespace ToolbookExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Toolbook example") {
      SetClientSize(390, 270);
      
      // On Windows the default size icon of toolbar is 16x16, on macOS is 32x32 and on gtk is 24x24...
      if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows") tabControl1->SetImageList(new wxImageList(16, 16));
      else if (wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Macintosh") tabControl1->SetImageList(new wxImageList(32, 32));
      else tabControl1->SetImageList(new wxImageList(24, 24));
      tabControl1->GetImageList()->Add(CreateImageFromColor(wxTheColourDatabase->Find("Red"), tabControl1->GetImageList()->GetSize()));
      tabControl1->GetImageList()->Add(CreateImageFromColor(wxTheColourDatabase->Find("Forest Green"), tabControl1->GetImageList()->GetSize()));
      tabControl1->GetImageList()->Add(CreateImageFromColor(wxTheColourDatabase->Find("Blue"), tabControl1->GetImageList()->GetSize()));
      tabControl1->GetImageList()->Add(CreateImageFromColor(wxTheColourDatabase->Find("Yellow"), tabControl1->GetImageList()->GetSize()));
      
      tabControl1->AddPage(tabPageRed, "Red", true, 0);
      tabControl1->AddPage(tabPageGreen, "Green", false, 1);
      tabControl1->AddPage(tabPageBlue, "Blue", false, 2);
      tabControl1->AddPage(tabPageYellow, "Yellow", false, 3);

      tabPageRed->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
      tabPageGreen->SetBackgroundColour(wxTheColourDatabase->Find("Forest Green"));
      tabPageBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));
      tabPageYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
    }
    
  private:
    wxBitmap CreateImageFromColor(const wxColor& color, const wxSize& size) {
      wxImage image(size.GetWidth(), size.GetHeight());
      image.InitAlpha();
      for (auto y = 0; y < size.GetHeight(); y++)
        for (auto x = 0; x < size.GetWidth(); x++)
          image.SetAlpha(x, y, 0);
      wxBitmap result(image);
      wxMemoryDC memoryDC(result);
      memoryDC.SetBrush(wxBrush(color));
      memoryDC.SetPen(wxPen(color));
      memoryDC.DrawEllipse(1, 1, result.GetSize().GetWidth() - 3, result.GetSize().GetHeight() - 3);
      return result;
    }

    wxPanel* panel = new wxPanel {this};
    wxToolbook* tabControl1 = new wxToolbook(panel, wxID_ANY, {10, 10}, {370, 250}, /*wxTBK_BUTTONBAR|*/wxTBK_HORZ_LAYOUT);
    wxNotebookPage* tabPageRed = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ToolbookExample::Application);
