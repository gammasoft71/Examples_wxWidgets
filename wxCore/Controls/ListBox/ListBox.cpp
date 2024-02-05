#include <wx/app.h>
#include <wx/frame.h>
#include <wx/listbox.h>
#include <wx/panel.h>
#include <wx/sizer.h>

using namespace std;

namespace ListBoxExample {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "ListBox example"} {
      SetClientSize(360, 240);
      
      listBoxLeft->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
        listBoxRight->Append(listBoxLeft->GetStringSelection());
        listBoxRight->SetSelection(0);
        listBoxLeft->Delete(listBoxLeft->GetSelection());
      });

      listBoxRight->Bind(wxEVT_LISTBOX_DCLICK, [&](wxCommandEvent& event) {
        listBoxLeft->Append(listBoxRight->GetStringSelection());
        listBoxLeft->SetSelection(0);
        listBoxRight->Delete(listBoxRight->GetSelection());
      });
      
      boxSizer->Add(listBoxLeft, wxSizerFlags(1).Expand().Border(wxALL, 20));
      boxSizer->Add(listBoxRight, wxSizerFlags(1).Expand().Border(wxALL, 20));
      
      panel->SetSizerAndFit(boxSizer);

      auto items = vector<wxString> {"draw", "cut", "paste", "delete", "open", "close", "remove", "edit", "find", "increment", "decrement", "write", "read", "post", "build", "make", "release", "create", "choose", "erase"};
      listBoxLeft->Append(static_cast<int>(items.size()), items.data());
      listBoxLeft->SetSelection(0);
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxBoxSizer* boxSizer = new wxBoxSizer {wxHORIZONTAL};
    wxListBox* listBoxLeft = new wxListBox {panel, wxID_ANY, wxDefaultPosition};
    wxListBox* listBoxRight = new wxListBox {panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, nullptr, wxLB_SORT};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(ListBoxExample::Application);
