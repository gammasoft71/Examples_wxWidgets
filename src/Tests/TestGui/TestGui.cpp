#include <stdexcept>
#include "Application.h"
#include <wx/wx.h>

class MainFrame : public wxFrame {
public:
  MainFrame() : wxFrame {nullptr, wxID_ANY, wxEmptyString} {
    SetClientSize({340, 230});
    Show();
    panel->Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
      wxPaintDC dc(panel);
      dc.SetPen(*wxTRANSPARENT_PEN);

      auto solidRedBrush = wxBrush(wxColour {255, 0, 0});
      dc.SetBrush(solidRedBrush);
      dc.DrawRectangle(10, 10, 100, 100);

      auto hatchBrush = wxBrush(wxColour {0, 255, 0});
      hatchBrush.SetStyle(wxBrushStyle::wxBRUSHSTYLE_CROSSDIAG_HATCH);
      dc.SetBrush(hatchBrush);
      dc.DrawRectangle(120, 10, 100, 100);

      auto stippleBrush = wxBrush(wxColour {0, 255, 0});
      stippleBrush.SetStyle(wxBrushStyle::wxBRUSHSTYLE_STIPPLE);
      stippleBrush.SetStipple(CreateHorizontalTexture(wxColour {0, 0, 255}, wxColour {255, 255, 0}));
      dc.SetBrush(stippleBrush);
      dc.DrawRectangle(230, 10, 100, 100);
    });
  }
  
private:
  wxBitmap CreateHorizontalTexture(const wxColor& foreColor, const wxColor& backColor) {
    wxBitmap result(wxSize{8, 8});
    result.UseAlpha();
    wxMemoryDC memoryDC(result);
    memoryDC.SetBrush({backColor});
    memoryDC.SetPen(*wxTRANSPARENT_PEN);
    memoryDC.DrawRectangle(0, 0, result.GetWidth(), result.GetHeight());
    memoryDC.SetBrush(*wxTRANSPARENT_BRUSH);
    memoryDC.SetPen(foreColor);
    memoryDC.DrawLine(0, 5, result.GetWidth(), 5);
    return result;
  }

  wxPanel* panel = new wxPanel {this};
};

int main() {
  auto application = new wxApplication;
  auto frame = new MainFrame;
  frame->Show();
  application->MainLoop();
}
