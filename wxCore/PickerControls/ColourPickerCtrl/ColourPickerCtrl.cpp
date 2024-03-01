#include <wx/app.h>
#include <wx/clrpicker.h>
#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace ColourPickerCtrlExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ColourPicker example"} {
      testZone->SetBackgroundColour(picker->GetColour());

      picker->Bind(wxEVT_COLOURPICKER_CHANGED, [&](wxColourPickerEvent& event) {
        testZone->Refresh();
        colourText->SetLabel(event.GetColour().GetAsString(wxC2S_HTML_SYNTAX));
      });
      
      testZone->Bind(wxEVT_PAINT, [&] (wxPaintEvent& event) {
        auto dc = wxPaintDC {testZone};
        PaintCheckerBoardPattern(dc, {0x66, 0x66, 0x66}, {0x99, 0x99, 0x99});
        dc.SetBrush({picker->GetColour()});
        dc.DrawRectangle({0, 0}, dc.GetSize());
      });
    }
    
  private:
    void PaintCheckerBoardPattern(wxDC& dc, const wxColour& foreColour, const wxColour& backColour) {
      static auto stipple = [&] {
        auto image = wxImage {16, 16};
        image.InitAlpha();
        for (auto y = 0; y < image.GetWidth(); ++y)
          for (auto x = 0; x < image.GetHeight(); ++x)
            image.SetAlpha(x, y, 0);
        auto pattern = wxBitmap {image};
        auto dc = wxMemoryDC {pattern};
        dc.SetPen({foreColour});
        for (auto point : std::vector<wxPoint> {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {12, 0}, {13, 0}, {14, 0}, {15, 0}, {0, 1}, {1, 1}, {2, 1}, {3, 1}, {12, 1}, {13, 1}, {14, 1}, {15, 1}, {0, 2}, {1, 2}, {2, 2}, {3, 2}, {12, 2}, {13, 2}, {14, 2}, {15, 2}, {0, 3}, {1, 3}, {2, 3}, {3, 3}, {12, 3}, {13, 3}, {14, 3}, {15, 3}, {4, 4}, {5, 4}, {6, 4}, {7, 4}, {8, 4}, {9, 4}, {10, 4}, {11, 4}, {4, 5}, {5, 5}, {6, 5}, {7, 5}, {8, 5}, {9, 5}, {10, 5}, {11, 5}, {4, 6}, {5, 6}, {6, 6}, {7, 6}, {8, 6}, {9, 6}, {10, 6}, {11, 6}, {4, 7}, {5, 7}, {6, 7}, {7, 7}, {8, 7}, {9, 7}, {10, 7}, {11, 7}, {4, 8}, {5, 8}, {6, 8}, {7, 8}, {8, 8}, {9, 8}, {10, 8}, {11, 8}, {4, 9}, {5, 9}, {6, 9}, {7, 9}, {8, 9}, {9, 9}, {10, 9}, {11, 9}, {4, 10}, {5, 10}, {6, 10}, {7, 10}, {8, 10}, {9, 10}, {10, 10}, {11, 10}, {4, 11}, {5, 11}, {6, 11}, {7, 11}, {8, 11}, {9, 11}, {10, 11}, {11, 11}, {0, 12}, {1, 12}, {2, 12}, {3, 12}, {12, 12}, {13, 12}, {14, 12}, {15, 12}, {0, 13}, {1, 13}, {2, 13}, {3, 13}, {12, 13}, {13, 13}, {14, 13}, {15, 13}, {0, 14}, {1, 14}, {2, 14}, {3, 14}, {12, 14}, {13, 14}, {14, 14}, {15, 14}, {0, 15}, {1, 15}, {2, 15}, {3, 15}, {12, 15}, {13, 15}, {14, 15}, {15, 15}})
          dc.DrawRectangle(point, {2, 2});
        return pattern;
      }();
      dc.SetBrush({backColour});
      dc.DrawRectangle({0, 0}, dc.GetSize());
      dc.SetBrush(wxBrush {stipple});
      dc.DrawRectangle({0, 0}, dc.GetSize());
    }

    wxPanel* panel = new wxPanel {this};
    wxColourPickerCtrl* picker = new wxColourPickerCtrl {panel, wxID_ANY, wxTheColourDatabase->Find("red"), {10, 10}, wxDefaultSize, wxCLRP_SHOW_ALPHA};
    wxPanel* testZone = new wxPanel {panel, wxID_ANY, {10, 50}, {200, 100}, wxBORDER_SUNKEN | wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL};
    wxStaticText* colourText = new wxStaticText {panel, wxID_ANY, picker->GetColour().GetAsString(wxC2S_HTML_SYNTAX), {10, 160}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ColourPickerCtrlExample::Application);
