#include <wx/wx.h>
#include <wx/treectrl.h>

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "TreeView example", wxDefaultPosition, wxSize(300, 300)) {
    wxTreeItemId rootId = this->treeView->AddRoot("Root");
    wxTreeItemId firstId = this->treeView->AppendItem(rootId, "First");
    this->treeView->AppendItem(firstId, "Second");
    this->treeView->AppendItem(firstId, "Third");
    wxTreeItemId fourthId = this->treeView->AppendItem(rootId, "Fourth");
    this->treeView->AppendItem(fourthId, "Fifth");
    this->treeView->AppendItem(fourthId, "Sixth");
    this->treeView->AppendItem(fourthId, "Seventh");
    this->treeView->ExpandAll();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxTreeCtrl* treeView = new wxTreeCtrl(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(150, 200));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
