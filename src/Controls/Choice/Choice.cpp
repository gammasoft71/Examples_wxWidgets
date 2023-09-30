#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/panel.h>

namespace ChoiceExample {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "Choice example") {
    for (int i = 1; i <= 10; ++i) {
      choice1->Append("item " + std::to_string(i));
    }
    choice1->SetSelection(0);
    choice1->Bind(wxEVT_CHOICE, &Frame::OnChoicClick, this);

    for (int i = 1; i <= 10; ++i) {
      choice2->Append("item " + std::to_string(i));
    }
    choice2->SetSelection(0);
    choice2->Bind(wxEVT_CHOICE, &Frame::OnChoicClick, this);
  }

private:
  void OnChoicClick(wxCommandEvent &e) {
    choice1->SetSelection(
        static_cast<wxChoice *>(e.GetEventObject())->GetSelection());
    choice2->SetSelection(
        static_cast<wxChoice *>(e.GetEventObject())->GetSelection());
  }
  wxPanel *panel = new wxPanel(this);
  wxChoice *choice1 = new wxChoice(panel, wxID_ANY, {10, 10});
  wxChoice *choice2 = new wxChoice(panel, wxID_ANY, {10, 50});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
} // namespace ChoiceExample

wxIMPLEMENT_APP(ChoiceExample::Application);
