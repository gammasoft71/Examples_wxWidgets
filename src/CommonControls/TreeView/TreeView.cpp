#include <wx/wx.h>
#include <wx/treectrl.h>

class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "TreeView example", wxDefaultPosition, wxSize(300, 300)) {
    wxTreeItemId rootId = treeView->AddRoot("Root");
    wxTreeItemId firstId = treeView->AppendItem(rootId, "First");
    treeView->AppendItem(firstId, "Second");
    treeView->AppendItem(firstId, "Third");
    wxTreeItemId fourthId = treeView->AppendItem(rootId, "Fourth");
    treeView->AppendItem(fourthId, "Fifth");
    treeView->AppendItem(fourthId, "Sixth");
    treeView->AppendItem(fourthId, "Seventh");
    treeView->ExpandAll();
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxTreeCtrl* treeView = new wxTreeCtrl(panel, wxID_ANY, wxPoint(10, 10), wxSize(150, 200));
};

class Application : public wxApp {
  bool OnInit() override {(new Frame())->Show(); return true;}
};

wxIMPLEMENT_APP(Application);
