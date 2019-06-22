#include <wx/wx.h>
#include <map>

enum wxOwnedID {
  wxID_OPENRECENT = 2,
  wxID_SHOW,
  wxID_HIDE,
};

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "MainMenu example", wxDefaultPosition, wxSize(300, 300)) {
    this->menuFile->Append(wxID_NEW, "New\tCtrl+N");
    this->menuFile->Append(wxID_OPEN, "Open...\tCtrl+o");
    this->menuFile->Append(wxID_OPENRECENT, "Open recent");
    this->menuFile->Append(wxID_CLOSE, "Close\tCtrl+W");
    this->menuFile->AppendSeparator();
    this->menuFile->Append(wxID_SAVE, "Save\tCtrl+s");
    this->menuFile->Append(wxID_SAVEAS, "Save as...");
    this->menuFile->AppendSeparator();
    this->menuFile->Append(wxID_EXIT, "Quit\tAlt+F4");

    this->menuEdit->Append(wxID_UNDO, "Undo\tCtrl+z");
    this->menuEdit->Append(wxID_REDO, "Redo\tCtrl+y");
    this->menuEdit->AppendSeparator();
    this->menuEdit->Append(wxID_CUT, "Cut\tCtrl+x");
    this->menuEdit->Append(wxID_COPY, "Copy\tCtrl+c");
    this->menuEdit->Append(wxID_PASTE, "Paste\tCtrl+v");
    this->menuEdit->AppendSeparator();
    this->menuEdit->Append(wxID_SELECTALL, "Select All\tCtrl+a");

    this->menuView->Append(wxID_SHOW, "Show");
    this->menuView->Append(wxID_HIDE, "Hide");

    this->mainMenu->Append(this->menuFile, "&File");
    this->mainMenu->Append(this->menuEdit, "&Edit");
    this->mainMenu->Append(this->menuView, "&View");

    this->SetMenuBar(this->mainMenu);
    
    this->mainMenu->Bind(wxEVT_COMMAND_MENU_SELECTED, [&](wxCommandEvent& event) {
      static std::map<int, std::string> names = {{wxID_NEW, "File/New"}, {wxID_OPEN, "File/Open..."}, {wxID_OPENRECENT, "File/Open recent"}, {wxID_CLOSE, "File/Close"}, {wxID_SAVE, "File/Save"}, {wxID_SAVEAS, "File/Save as..."}, {wxID_EXIT, "File/Quit"}, {wxID_UNDO, "Edit/Undo"}, {wxID_REDO, "Edit/Redo"}, {wxID_CUT, "Edit/Cut"}, {wxID_COPY, "Edit/Copy"}, {wxID_PASTE, "Edit/Paste"}, {wxID_SELECTALL, "Edit/Select All"}, {wxID_SHOW, "View/Show"}, {wxID_HIDE, "View/Hide"}, {wxID_ANY, "Any"}};
      if (names.find(event.GetId()) != names.end())
        this->listBox1->Append(names[event.GetId()]);
      else
        this->listBox1->Append("Unknown");
      if (event.GetId() == wxID_EXIT)
        this->Close();
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxMenuBar* mainMenu = new wxMenuBar();
  wxMenu* menuFile = new wxMenu();
  wxMenu* menuEdit = new wxMenu();
  wxMenu* menuView = new wxMenu();
  wxListBox* listBox1 = new wxListBox(this->panel, wxID_ANY, wxPoint(10, 10), wxSize(280, 260));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
