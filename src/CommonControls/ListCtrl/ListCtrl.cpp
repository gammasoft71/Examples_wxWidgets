#include <wx/app.h>
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/panel.h>

#include "Ai16.xpm"
#include "Ai48.xpm"
#include "Avi16.xpm"
#include "Avi48.xpm"
#include "Bmp16.xpm"
#include "Bmp48.xpm"

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "ListCtrl example") {
      SetClientSize(350, 260);

      imageListLarge.Add(wxBitmap {aiIcon48});
      imageListLarge.Add(wxBitmap {aviIcon48});
      imageListLarge.Add(wxBitmap {bmpIcon48});
      listCtrl->SetImageList(&imageListLarge, wxIMAGE_LIST_NORMAL);
      
      imageListSmall.Add(wxBitmap {aiIcon16});
      imageListSmall.Add(wxBitmap {aviIcon16});
      imageListSmall.Add(wxBitmap {bmpIcon16});
      listCtrl->SetImageList(&imageListSmall, wxIMAGE_LIST_SMALL);

      listCtrl->AppendColumn("Name", wxLIST_FORMAT_LEFT, 80);
      listCtrl->AppendColumn("Type", wxLIST_FORMAT_LEFT, 50);
      listCtrl->AppendColumn("Size", wxLIST_FORMAT_LEFT, 50);
      listCtrl->AppendColumn("Comment", wxLIST_FORMAT_LEFT, 140);
      
      listCtrl->InsertItem(0, "First");
      listCtrl->SetItem(0, 1, "Movie");
      listCtrl->SetItem(0, 2, "5359");
      listCtrl->SetItem(0, 3, "This is the first item");
      listCtrl->SetItemImage(0, 1);
      
      listCtrl->InsertItem(1, "Second");
      listCtrl->SetItem(1, 1, "Picture");
      listCtrl->SetItem(1, 2, "1256");
      listCtrl->SetItem(1, 3, "This is the second item");
      listCtrl->SetItemImage(1, 0);

      listCtrl->InsertItem(2, "Third");
      listCtrl->SetItem(2, 1, "Picture");
      listCtrl->SetItem(2, 2, "4284");
      listCtrl->SetItem(2, 3, "This is the third item");
      listCtrl->SetItemImage(2, 2);

      listCtrl->wxWindow::Update();

      choice1->Append("LargeIcon", reinterpret_cast<void*>(wxLC_ICON));
      choice1->Append("Detail", reinterpret_cast<void*>(wxLC_REPORT));
      choice1->Append("SmallIcon", reinterpret_cast<void*>(wxLC_SMALL_ICON));
      choice1->Append("List", reinterpret_cast<void*>(wxLC_LIST));
      choice1->SetSelection(1);
      choice1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& event) {
        listCtrl->SetSingleStyle(reinterpret_cast<long long>(choice1->GetClientData(choice1->GetSelection())));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxListCtrl* listCtrl = new wxListCtrl(panel, wxID_ANY, {10, 10}, {330, 200}, wxLC_REPORT|wxSIMPLE_BORDER);
    wxChoice* choice1 = new wxChoice(panel, wxID_ANY, {10, 220});
    wxImageList imageListLarge {48, 48};
    wxImageList imageListSmall {16, 16};
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
