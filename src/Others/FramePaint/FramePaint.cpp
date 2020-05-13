#include <wx/wx.h>
#include <wx/statline.h>

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

  class Window : public wxFrame {
  public:
    Window() : wxFrame(nullptr, wxID_ANY, "Paint example") {
      SetPosition({100, 100});
      SetClientSize(640, 480);
      
      Bind(wxEVT_PAINT, [&](wxPaintEvent& event) {
        wxPaintDC dc(this);
        FillRectangle(dc, {{0x00, 0x00, 0xFF}, wxBRUSHSTYLE_SOLID}, 0, 0, 640, 480);
        Clear(dc, {0xFF, 0xFF, 0xE0});
        DrawRectangle(dc,{{0xFF, 0xB6, 0xC1}, 10, wxPENSTYLE_SOLID}, GetClientRect());
        DrawLine(dc, {{0x80, 0xC4, 0xDE}, 5, wxPENSTYLE_SOLID}, 20, 60, 260, 60);
        FillRectangle(dc, {{0xAD, 0xD8, 0xE6}, wxBRUSHSTYLE_SOLID}, 50, 300, 400, 50);
        DrawLine(dc, {{0xFF, 0x00, 0x00}, 1, wxPENSTYLE_SOLID}, 0, 0, 1, 1);
        DrawLString(dc, "Draw string", {PointsToNativeFontGraphicsUntit(34), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, "Arial"}, {{0x90, 0xEE, 0x90}, wxBRUSHSTYLE_SOLID}, 20, 0);
        FillRectangle(dc, wxBrush(wxColour(0x20, 0xB2, 0xAA)), 400, 70, 100, 200);
        DrawArc(dc, {{0x00, 0x00, 0x0}, 10, wxPENSTYLE_SOLID}, 400, 70, 100, 200, 45, 270);
        DrawEllipse(dc, {{0xFF, 0x00, 0x00}, 10, wxPENSTYLE_SOLID}, 100, 80, 200, 200);
        FillPie(dc, {{0x00, 0x80, 0x00}, wxBRUSHSTYLE_SOLID}, 120, 100, 160, 160, 45.0f, 270.0f);
        FillPie(dc, {{0x90, 0xEE, 0x90}, wxBRUSHSTYLE_SOLID}, 120, 100, 160, 160, 270.0f, 180.0f);
        DrawBezier(dc, {{0x00, 0x00, 0x00}, 1, wxPENSTYLE_SOLID}, 100, 100, 150, 150, 200, 100, 250, 50);
      });
    }
    
    static void Clear(wxPaintDC& dc, const wxColour& color) {
      dc.SetBackground({color});
      dc.Clear();
    }
    
    static void DrawLine(wxPaintDC& dc, const wxPen& pen, int x1, int y1, int x2, int y2) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      dc.DrawLine(x1, y1, x2, y2);
    }
    
    static void DrawRectangle(wxPaintDC& dc, const wxPen& pen, const wxRect& rect) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      dc.DrawRectangle(rect);
    }

    static void DrawRectangle(wxPaintDC& dc, const wxPen& pen, int x, int y, int width, int height) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      dc.DrawRectangle(x, y, width, height);
    }

    static void FillRectangle(wxPaintDC& dc, const wxBrush& brush, int x, int y, int width, int height) {
      dc.SetBrush(brush);
      dc.SetPen(*wxTRANSPARENT_PEN);
      dc.DrawRectangle(x, y, width, height);
    }
    
    static void DrawLString(wxPaintDC& dc, const wxString& text, const wxFont& font, const wxBrush& brush, float x, float y) {
      dc.SetFont(font);
      dc.SetTextForeground(brush.GetColour());
      dc.DrawText(text, x, y);
    }
    
    static void DrawArc(wxPaintDC& dc, const wxPen& pen, int x, int y, int width, int height, int startAngle, int sweepAngle) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      dc.DrawEllipticArc(x, y, width, height, startAngle, startAngle + sweepAngle);
    }
    
    static void DrawEllipse(wxPaintDC& dc, const wxPen& pen, int x, int y, int width, int height) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      dc.DrawEllipse(x, y, width, height);
    }
    
    static void FillPie(wxPaintDC& dc, const wxBrush& brush, int x, int y, int width, int height, float startAngle, float sweepAngle) {
      dc.SetBrush(brush);
      dc.SetPen(*wxTRANSPARENT_PEN);
      dc.DrawEllipticArc(x, y, width, height, startAngle, startAngle + sweepAngle);
    }
    
    static void DrawBezier(wxPaintDC& dc, const wxPen& pen, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
      dc.SetBrush(*wxTRANSPARENT_BRUSH);
      dc.SetPen(pen);
      wxPoint points[] = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
      dc.DrawSpline(4, points);
    }
  };
  
  class Application : public wxApp {
    bool OnInit() override {
      (new Window())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
