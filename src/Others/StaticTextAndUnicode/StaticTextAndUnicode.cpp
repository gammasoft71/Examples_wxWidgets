#include <utility>
#include <vector>
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stattext.h>

using namespace std;

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "StaticText and unicode text example") {
      SetClientSize(400, 350);
      SetBackgroundColour(wxColour(0, 127, 127));
      SetForegroundColour(wxTheColourDatabase->Find(("Black")));

      for (auto index = 0; index < languages.size(); ++index) {
        items[index].first = new wxStaticText(panel, wxID_ANY, languages[index].first, {10, 10 + index * 30}, {150, wxDefaultCoord});
        items[index].first->SetForegroundColour(wxTheColourDatabase->Find(("Black")));
        items[index].second = new wxStaticText(panel, wxID_ANY, languages[index].second, {160, 10 + index * 30}, {220, wxDefaultCoord});
        items[index].second->SetForegroundColour(wxTheColourDatabase->Find(("Black")));
      }
    }
    
  private:
    vector<pair<wxString, wxString>> languages {
      {"Arabic", wxT("\u0627\u0644\u0643\u0644\u0645\u0629 \u0627\u0644\u0639\u0631\u0628\u064A\u0629")},
      {"Trad. Chinese", wxT("\u4E2D\u570B\u7684\u6F22\u5B57")},
      {"Simpl. Chinese:", wxT("\u6C49\u8BED")},
      {"French", wxT("Langue fran\u00E7aise")},
      {"Greek", wxT("\u0395\u03BB\u03BB\u03B7\u03BD\u03B9\u03BA\u03AE \u03B3\u03BB\u03CE\u03C3\u03C3\u03B1")},
      {"Hebrew", wxT("\u05DB\u05EA\u05D1 \u05E2\u05D1\u05E8\u05D9\u05EA")},
      {"Hindi", wxT("\u0939\u093f\u0928\u094d\u0926\u0940 \u092d\u093e\u0937\u093e")},
      {"Icelandic", wxT("\u00CDslenska")},
      {"Japanese", wxT("\u65E5\u672C\u8A9E\u306E\u3072\u3089\u304C\u306A, \u6F22\u5B57\u3068\u30AB\u30BF\u30AB\u30CA")},
      {"Korean", wxT("\uB300\uD55C\uBBFC\uAD6D\uC758 \uD55C\uAE00")},
      {"Russian", wxT("\u0420\u0443\u0441\u0441\u043A\u0438\u0439 \u044F\u0437\u044B\u043A")}
    };
    vector<pair<wxStaticText*, wxStaticText*>> items {languages.size()};
    wxPanel* panel = new wxPanel(this);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
