#include <wx/wx.h>
#include <wx/toolbook.h>

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Toolbook example") {
      SetClientSize(390, 270);
      
      // On Windows the default size icon of toolbar is 16x16 and not 32x32...
      auto toolbarIconSize = wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows" ? 16 : 32;
      tabControl1->SetImageList(new wxImageList(toolbarIconSize, toolbarIconSize));
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
      wxBitmap result(size);
      wxMemoryDC memoryDC(result);
      memoryDC.SetBrush(wxBrush(color));
      memoryDC.SetPen(*wxBLACK_PEN);
      memoryDC.DrawRectangle(0, 0, result.GetSize().GetWidth(), result.GetSize().GetHeight());
      return result;
    }
    wxPanel* panel = new wxPanel(this);
    wxToolbook* tabControl1 = new wxToolbook(panel, wxID_ANY, {10, 10}, {370, 250});
    wxNotebookPage* tabPageRed = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
