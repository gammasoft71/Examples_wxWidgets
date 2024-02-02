#include <wx/wx.h>

namespace StaticBoxExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticBox example") {
      SetClientSize(640, 480);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxStaticBox* staticBox1 = new wxStaticBox(panel, wxID_ANY, "GroupBox 1", {10, 10}, {305, 460});
    wxStaticBox* staticBox2 = new wxStaticBox(panel, wxID_ANY, wxEmptyString, {325, 10}, {305, 460});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame)->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(StaticBoxExample::Application);
