#include <wx/wx.h>
#include <wx/msgout.h>

namespace Examples {
#if defined(__WXOSX__)
  int PointsToNativeFontGraphicsUntit(int size) {
    return static_cast<float>(size) / wxScreenDC().GetPPI().GetHeight() * 96.0f;  // font is in pixels and not in points
  }
#else
  int PointsToNativeFontGraphicsUntit(int size) {
    return size;  // font is in points
  }
#endif

  class Frame1 : public wxFrame {
  public:
    Frame1() : wxFrame(nullptr, wxID_ANY, "Frame1") {
      SetClientSize(300, 300);
      auto font = GetFont();
      font.SetPointSize(PointsToNativeFontGraphicsUntit(18));
      font.SetWeight(wxFontWeight::wxFONTWEIGHT_BOLD);
      SetFont(font);
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        dc.SetPen(*wxTRANSPARENT_PEN);
        if (AppActive()) {
          dc.SetBrush({wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_MENUHILIGHT)});
          dc.DrawRectangle({10, 10, 280, 50});
          dc.DrawText("Application is active", 10, 10);
        } else {
          dc.SetBrush({wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_BTNFACE)});
          dc.DrawRectangle({10, 10, 280, 50});
          dc.DrawText("Application is inactive", 10, 10);
        }
      });
    }

    bool AppActive() const {return appActive;}
    void AppActive(bool value) {appActive = value;}

  private:
    wxPanel* panel = new wxPanel(this);
    bool appActive = true;
  };

  class Application : public wxApp {
    bool ProcessEvent (wxEvent &event) override {
      if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
        frame1->AppActive(dynamic_cast<wxActivateEvent&>(event).GetActive());
        wxMessageOutputDebug().Printf("wxEVT_ACTIVATE_APP [active=%s]", frame1->AppActive() ? "true" : "false");
        frame1->Refresh();
      }
      
      return wxApp::ProcessEvent(event);
    }

    bool OnInit() override {
      frame1 = new Frame1();
      frame1->Show();
      return true;
    }
    
    Frame1* frame1 = nullptr;
  };
}

wxIMPLEMENT_APP(Examples::Application);
