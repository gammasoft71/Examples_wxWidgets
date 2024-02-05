#include <wx/app.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/rearrangectrl.h>
#include <wx/stattext.h>

using namespace std;

namespace RearrangeDialogExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "RearangeDialog example"} {
      auto colorItemss = vector<wxString> {"Red", "Green", "Blue", "Yellow"};
      colors = wxArrayString {colorItemss.size(), colorItemss.data()};
      for (auto item : {3, 0, 1, 2})
        order.push_back(item);


      button->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
        label->SetLabel("");
        auto dialog = wxRearrangeDialog {nullptr, "You can also uncheck the colors you don't like at all.", "Sort the colors in order of preference", order, colors};
        if (dialog.ShowModal() == wxID_OK) {
          order = dialog.GetOrder();
          for (size_t n = 0; n < order.size(); n++) {
            if (order[n] >= 0) {
              label->SetLabel(wxString::Format("Your most preferred color is \"%s\"", colors[order[n]]));
              break;
            }
          }
        } else
          label->SetLabel("(none)");
      });
    }
    
  private:
    wxArrayString colors;
    wxArrayInt order;
    wxPanel* panel = new wxPanel {this};
    wxButton* button = new wxButton {panel, wxID_ANY, "Rearange...", {10, 10}};
    wxStaticText* label = new wxStaticText {panel, wxID_ANY, "(none)", {10, 50}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(RearrangeDialogExample::Application);
