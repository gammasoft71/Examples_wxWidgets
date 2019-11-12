#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Choice example", wxDefaultPosition, wxSize(300, 300)) {
    choice->Append("item1");
    choice->Append("item2");
    choice->Append("item3");
    choice->Append("item4");
    choice->Append("item5");
    choice->Append("item6");
    choice->Append("item7");
    choice->Append("item8");
    choice->Append("item9");
    choice->Append("item10");
    choice->Select(0);
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxChoice* choice = new wxChoice(panel, wxID_ANY, wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
