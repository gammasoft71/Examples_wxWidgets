#include <wx/wx.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>

#include "Ai16.xpm"
#include "Ai48.xpm"
#include "Avi16.xpm"
#include "Avi48.xpm"
#include "Bmp16.xpm"
#include "Bmp48.xpm"

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "ListView example", wxDefaultPosition) {
    SetClientSize(350, 260);

    imageListLarge.Add(wxIcon(aiIcon48));
    imageListLarge.Add(wxIcon(aviIcon48));
    imageListLarge.Add(wxIcon(bmpIcon48));
    listView->SetImageList(&imageListLarge, wxIMAGE_LIST_NORMAL);
    
    imageListSmall.Add(wxIcon(aiIcon16));
    imageListSmall.Add(wxIcon(aviIcon16));
    imageListSmall.Add(wxIcon(bmpIcon16));
    listView->SetImageList(&imageListSmall, wxIMAGE_LIST_SMALL);

    listView->AppendColumn("Name", wxLIST_FORMAT_LEFT, 80);
    listView->AppendColumn("Type", wxLIST_FORMAT_LEFT, 50);
    listView->AppendColumn("Size", wxLIST_FORMAT_LEFT, 50);
    listView->AppendColumn("Comment", wxLIST_FORMAT_LEFT, 140);
    
    listView->InsertItem(0, "First");
    listView->SetItem(0, 1, "Movie");
    listView->SetItem(0, 2, "5359");
    listView->SetItem(0, 3, "This is the first item");
    listView->SetItemImage(0, 1);
    
    listView->InsertItem(1, "Second");
    listView->SetItem(1, 1, "Picture");
    listView->SetItem(1, 2, "1256");
    listView->SetItem(1, 3, "This is the second item");
    listView->SetItemImage(1, 0);

    listView->InsertItem(2, "Third");
    listView->SetItem(2, 1, "Picture");
    listView->SetItem(2, 2, "4284");
    listView->SetItem(2, 3, "This is the third item");
    listView->SetItemImage(2, 2);

    listView->wxWindow::Update();

    comboBox1->Append("LargeIcon", (void*)wxLC_ICON);
    comboBox1->Append("Detail", (void*)wxLC_REPORT);
    comboBox1->Append("SmallIcon", (void*)wxLC_SMALL_ICON);
    comboBox1->Append("List", (void*)wxLC_LIST);
    comboBox1->SetSelection(1);
    comboBox1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& event) {
      listView->SetSingleStyle((long long)comboBox1->GetClientData(comboBox1->GetSelection()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxListCtrl* listView = new wxListCtrl(panel, wxID_ANY, wxPoint(10, 10), wxSize(330, 200), wxLC_REPORT | wxSIMPLE_BORDER);
  wxChoice* comboBox1 = new wxChoice(panel, wxID_ANY, wxPoint(10, 220));
  wxImageList imageListLarge { 48, 48 };
  wxImageList imageListSmall { 16, 16 };
};

class Application : public wxApp {
  bool OnInit() override {(new Form())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
