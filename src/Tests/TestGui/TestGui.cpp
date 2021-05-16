#include <memory>
#include <stdexcept>
#include "Application.h"
#include <wx/wx.h>
#include <wx/graphics.h>

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
      stippleBrush.SetStipple(CreateHorizontalTexture2(image, wxColour {255, 0, 0}, wxColour {255, 255, 0}));
      dc.SetBrush(stippleBrush);
      dc.DrawRectangle(230, 10, 100, 100);
    });
  }

private:

  wxImage& Clear(wxImage& image, const wxColor& backColor) {
    wxBitmap bitmap(image);
    wxMemoryDC memoryDC(bitmap);
    wxGraphicsContext* g = wxGraphicsContext::Create(memoryDC);
    g->SetBrush({backColor});
    auto path = g->CreatePath();
    path.AddRectangle(0, 0, 8, 8);
    g->FillPath(path);
    g->Flush();
    image = bitmap.ConvertToImage();
    return image;
  }

  wxImage& DrawPointOne(wxImage& image, const wxColor& foreColor) {
    wxBitmap bitmap(image);
    wxMemoryDC memoryDC(bitmap);
    wxGraphicsContext* g = wxGraphicsContext::Create(memoryDC);
    g->SetBrush({foreColor});
    auto path = g->CreatePath();
    path.AddRectangle(1, 1, 1, 1);
    g->FillPath(path);
    g->Flush();
    image = bitmap.ConvertToImage();
    return image;
  }

  wxImage& DrawPointTwo(wxImage& image, const wxColor& foreColor) {
    wxBitmap bitmap(image);
    wxMemoryDC memoryDC(bitmap);
    wxGraphicsContext* g = wxGraphicsContext::Create(memoryDC);
    g->SetBrush({foreColor});
    auto path = g->CreatePath();
    path.AddRectangle(1, 5, 1, 1);
    g->FillPath(path);
    g->Flush();
    image = bitmap.ConvertToImage();
    return image;
  }

  wxImage& DrawPointThree(wxImage& image, const wxColor& foreColor) {
    wxBitmap bitmap(image);
    wxMemoryDC memoryDC(bitmap);
    wxGraphicsContext* g = wxGraphicsContext::Create(memoryDC);
    g->SetBrush({foreColor});
    auto path = g->CreatePath();
    path.AddRectangle(5, 1, 1, 1);
    g->FillPath(path);
    image = bitmap.ConvertToImage();
    return image;
  }

  wxImage& DrawPointFour(wxImage& image, const wxColor& foreColor) {
    wxBitmap bitmap(image);
    wxMemoryDC memoryDC(bitmap);
    wxGraphicsContext* g = wxGraphicsContext::Create(memoryDC);
    g->SetBrush({foreColor});
    auto path = g->CreatePath();
    path.AddRectangle(5, 5, 1, 1);
    g->FillPath(path);
    g->Flush();
    image = bitmap.ConvertToImage();
    return image;
  }

  wxImage& CreateHorizontalTexture(wxImage& image, const wxColor& foreColor, const wxColor& backColor) {
    Clear(image, backColor);
    DrawPointOne(image, foreColor);
    DrawPointTwo(image, foreColor);
    DrawPointThree(image, foreColor);
    DrawPointFour(image, foreColor);
    return image;
  }

  wxImage& CreateHorizontalTexture2(wxImage& image, const wxColor& foreColor, const wxColor& backColor) {
    wxBitmap bitmap(image);
    {
      wxGraphicsContext* g = wxGraphicsContext::Create(wxMemoryDC(bitmap));
      g->SetBrush({backColor});
      auto path = g->CreatePath();
      path.AddRectangle(0, 0, 8, 8);
      g->FillPath(path);
      image = bitmap.ConvertToImage();
    }

    {
      wxGraphicsContext* g = wxGraphicsContext::Create(wxMemoryDC(bitmap));
      g->SetBrush({foreColor});
      auto path = g->CreatePath();
      path.AddRectangle(1, 1, 1, 1);
      g->FillPath(path);
      image = bitmap.ConvertToImage();
    }

    {
    wxGraphicsContext* g = wxGraphicsContext::Create(wxMemoryDC(bitmap));
      g->SetBrush({foreColor});
      auto path = g->CreatePath();
      path.AddRectangle(1, 5, 1, 1);
      g->FillPath(path);
      image = bitmap.ConvertToImage();
    }

    {
    wxGraphicsContext* g = wxGraphicsContext::Create(wxMemoryDC(bitmap));
      g->SetBrush({foreColor});
      auto path = g->CreatePath();
      path.AddRectangle(5, 1, 1, 1);
      g->FillPath(path);
      image = bitmap.ConvertToImage();
    }

    {
      wxGraphicsContext* g = wxGraphicsContext::Create(wxMemoryDC(bitmap));
      g->SetBrush({foreColor});
      auto path = g->CreatePath();
      path.AddRectangle(5, 5, 1, 1);
      g->FillPath(path);
      image = bitmap.ConvertToImage();
    }
    return image;
  }

  wxPanel* panel = new wxPanel {this};
  wxImage image {8, 8};
};

int main() {
  auto application = new wxApplication;
  auto frame = new MainFrame;
  frame->Show();
  application->MainLoop();
}
