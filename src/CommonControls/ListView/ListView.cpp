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
    this->SetClientSize(350, 260);

    this->imageListLarge.Add(wxIcon(aiIcon48));
    this->imageListLarge.Add(wxIcon(aviIcon48));
    this->imageListLarge.Add(wxIcon(bmpIcon48));
    this->listView->SetImageList(&this->imageListLarge, wxIMAGE_LIST_NORMAL);
    
    this->imageListSmall.Add(wxIcon(aiIcon16));
    this->imageListSmall.Add(wxIcon(aviIcon16));
    this->imageListSmall.Add(wxIcon(bmpIcon16));
    this->listView->SetImageList(&this->imageListSmall, wxIMAGE_LIST_SMALL);

    this->listView->AppendColumn("Name", wxLIST_FORMAT_LEFT, 80);
    this->listView->AppendColumn("Type", wxLIST_FORMAT_LEFT, 50);
    this->listView->AppendColumn("Size", wxLIST_FORMAT_LEFT, 50);
    this->listView->AppendColumn("Comment", wxLIST_FORMAT_LEFT, 140);
    
    this->listView->InsertItem(0, "First");
    this->listView->SetItem(0, 1, "Movie");
    this->listView->SetItem(0, 2, "5359");
    this->listView->SetItem(0, 3, "This is the first item");
    this->listView->SetItemImage(0, 1);
    
    this->listView->InsertItem(1, "Second");
    this->listView->SetItem(1, 1, "Picture");
    this->listView->SetItem(1, 2, "1256");
    this->listView->SetItem(1, 3, "This is the second item");
    this->listView->SetItemImage(1, 0);

    this->listView->InsertItem(2, "Third");
    this->listView->SetItem(2, 1, "Picture");
    this->listView->SetItem(2, 2, "4284");
    this->listView->SetItem(2, 3, "This is the third item");
    this->listView->SetItemImage(2, 2);
    this->listView->Update();
    
    this->comboBox1->Append("LargeIcon", (void*)wxLC_ICON);
    this->comboBox1->Append("Detail", (void*)wxLC_REPORT);
    this->comboBox1->Append("SmallIcon", (void*)wxLC_SMALL_ICON);
    this->comboBox1->Append("List", (void*)wxLC_LIST);
    this->comboBox1->SetSelection(1);
    this->comboBox1->Bind(wxEVT_CHOICE, [&](wxCommandEvent& event) {
      this->listView->SetSingleStyle((long long)this->comboBox1->GetClientData(this->comboBox1->GetSelection()));
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxListCtrl* listView = new wxListCtrl(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(330, 200), wxLC_REPORT | wxSIMPLE_BORDER);
  wxChoice* comboBox1 = new wxChoice(this->panel, wxID_ANY, wxPoint(10, 220));
  wxImageList imageListLarge { 48, 48 };
  wxImageList imageListSmall { 16, 16 };
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
