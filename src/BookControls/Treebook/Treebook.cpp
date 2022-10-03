#include <wx/wx.h>
#include <wx/treebook.h>

// Workaround : with wxWidgets version <= 3.2.0 Tree position and size are failed on macOS (and Linux)
#if defined(__APPLE__) || defined(__UNIX__)
#include <wx/treectrl.h>
class TreeBook : public wxTreebook {
public:
  TreeBook(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxBK_DEFAULT, const wxString& name = wxEmptyString) : wxTreebook(parent, id, pos, size, style, name) {}
  
  bool AddPage(wxWindow *page, const wxString& text, bool bSelect = false, int imageId = NO_IMAGE) override {
    save_context backup(this, bSelect);
    auto result = wxTreebook::AddPage(page, text, true, imageId);
    InternalFixTreeBookCreattion();
    return result;
  }
  
  bool AddSubPage(wxWindow *page, const wxString& text, bool bSelect = false, int imageId = NO_IMAGE) override {
    save_context backup(this, bSelect);
    auto result = wxTreebook::AddSubPage(page, text, true, imageId);
    return result;
  }

  bool InsertPage(size_t pos, wxWindow *page, const wxString& text, bool bSelect = false, int imageId = NO_IMAGE) override {
    save_context backup(this, bSelect);
    auto result = wxTreebook::InsertPage(pos, page, text, true, imageId);
    InternalFixTreeBookCreattion();
    return result;
  }
  
  bool InsertSubPage(size_t pos, wxWindow *page, const wxString& text, bool bSelect = false, int imageId = NO_IMAGE) override {
    save_context backup(this, bSelect);
    auto result = wxTreebook::InsertSubPage(pos, page, text, true, imageId);
    InternalFixTreeBookCreattion();
    return result;
  }

private:
  class save_context {
  public:
    save_context(TreeBook* treeBook, bool bSelect) : treeBook_(treeBook) {selection_ = !bSelect ? treeBook_->GetSelection() : wxNOT_FOUND;}
    ~save_context() {if (selection_ != wxNOT_FOUND) treeBook_->SetSelection(selection_);}
  private:
    TreeBook* treeBook_ = nullptr;
    int selection_ = wxNOT_FOUND;
  };
  void InternalFixTreeBookCreattion() {
    static bool first_ = true;
    if (first_) {
      GetTreeCtrl()->SetBackgroundColour({255, 255, 255});
      GetTreeCtrl()->SetBackgroundColour(wxSystemSettings::GetColour(wxSystemColour::wxSYS_COLOUR_WINDOW));
      GetTreeCtrl()->SetPosition({0, 0});
      GetTreeCtrl()->SetSize({84, GetSize().GetHeight()});
      GetCurrentPage()->SetPosition({GetCurrentPage()->GetPosition().x + 20, GetCurrentPage()->GetPosition().y});
      first_ = false;
    } else
      GetTreeCtrl()->SetSize({GetCurrentPage()->GetPosition().x - 7, GetSize().GetHeight()});
  }
};
#else
using TreeBook = wxTreebook;
#endif

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Treebook example") {
      SetClientSize(390, 270);
      Show();
      
      tabControl1->AddPage(tabPageRed, "Red");
      tabControl1->AddSubPage(tabPageGreen, "Green");
      tabControl1->AddSubPage(tabPageBlue, "Blue");
      tabControl1->AddPage(tabPageYellow, "Yellow");

      tabPageRed->SetBackgroundColour(wxTheColourDatabase->Find("Red"));
      tabPageGreen->SetBackgroundColour(wxTheColourDatabase->Find("Forest Green"));
      tabPageBlue->SetBackgroundColour(wxTheColourDatabase->Find("Blue"));
      tabPageYellow->SetBackgroundColour(wxTheColourDatabase->Find("Yellow"));
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    TreeBook* tabControl1 = new TreeBook(panel, wxID_ANY, {10, 10}, {370, 250});
    wxNotebookPage* tabPageRed = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageGreen = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageBlue = new wxNotebookPage(tabControl1, wxID_ANY);
    wxNotebookPage* tabPageYellow = new wxNotebookPage(tabControl1, wxID_ANY);
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
