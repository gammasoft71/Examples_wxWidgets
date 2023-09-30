#include <map>
#include <string>
#include <wx/artprov.h>
#include <wx/aui/auibar.h>
#include <wx/aui/framemanager.h>
#include <wx/wx.h>

namespace AuiToolbarExample {
class Frame : public wxFrame {
public:
  Frame() : wxFrame(nullptr, wxID_ANY, "AuiToolbar example") {
    SetClientSize(640, 480);

    // On Windows the default size icon of toolbar is 16x16 and not 32x32...
    wxSize bitmapSize =
        wxPlatformInfo::Get().GetOperatingSystemFamilyName() == "Windows"
            ? wxSize(16, 16)
            : wxDefaultSize;

    toolBar1->AddTool(
        wxID_NEW, "&New",
        wxArtProvider::GetBitmap(wxART_NEW, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddTool(
        wxID_OPEN, "&Open...",
        wxArtProvider::GetBitmap(wxART_FILE_OPEN, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddTool(
        wxID_SAVE, "&Save",
        wxArtProvider::GetBitmap(wxART_FILE_SAVE, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddSeparator();
    toolBar1->AddTool(
        wxID_CUT, "Cu&t",
        wxArtProvider::GetBitmap(wxART_CUT, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddTool(
        wxID_COPY, "&Copy",
        wxArtProvider::GetBitmap(wxART_COPY, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddTool(
        wxID_PASTE, "&Paste",
        wxArtProvider::GetBitmap(wxART_PASTE, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddSeparator();
    toolBar1->AddTool(
        wxID_PRINT, "&Print...",
        wxArtProvider::GetBitmap(wxART_PRINT, wxART_TOOLBAR, bitmapSize));
    toolBar1->AddSeparator();
    toolBar1->AddControl(choice);
    toolBar1->AddStretchSpacer();
    toolBar1->AddTool(
        wxID_ABOUT, "&About...",
        wxArtProvider::GetBitmap(wxART_HELP, wxART_TOOLBAR, bitmapSize));
    toolBar1->Realize();
    toolBar1->Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
      static std::map<int, std::string> names = {
          {wxID_NEW, "New"},        {wxID_OPEN, "Open..."},
          {wxID_SAVE, "Save"},      {wxID_EXIT, "Quit"},
          {wxID_CUT, "Cut"},        {wxID_COPY, "Copy"},
          {wxID_PASTE, "Paste"},    {wxID_PRINT, "Print..."},
          {wxID_ABOUT, "About..."}, {wxID_ANY, "Any"}};
      listBox1->Append(names.find(event.GetId()) != names.end()
                           ? names[event.GetId()]
                           : "Unknown");
      if (event.GetId() == wxID_EXIT)
        Close();
    });

    toolBar2->AddTool(
        wxID_UNDO, "Undo",
        wxArtProvider::GetBitmap(wxART_UNDO, wxART_TOOLBAR, bitmapSize));
    toolBar2->AddTool(
        wxID_REDO, "Redo",
        wxArtProvider::GetBitmap(wxART_REDO, wxART_TOOLBAR, bitmapSize));
    auto select_all_tool = toolBar2->AddLabel(wxID_SELECTALL, "Select all");
    toolBar2->AddSeparator();
    toolBar2->AddControl(gauge);
    toolBar2->Realize();
    toolBar2->Bind(wxEVT_MENU, [&](wxCommandEvent &event) {
      static std::map<int, std::string> names = {
          {wxID_UNDO, "Undo..."},
          {wxID_REDO, "Redo..."},
          {wxID_SELECTALL, "Select all..."},
          {wxID_ANY, "Any"}};
      if (names.find(event.GetId()) != names.end())
        listBox1->Append(names[event.GetId()]);
      if (event.GetId() == wxID_EXIT)
        Close();
    });

    auiManager->AddPane(
        listBox1,
        wxAuiPaneInfo().Center().CaptionVisible(false).CloseButton(false));
    auiManager->AddPane(toolBar1, wxAuiPaneInfo()
                                      .ToolbarPane()
                                      .Top()
                                      .Caption("Standard toolbar")
                                      .CloseButton(false));
    auiManager->AddPane(toolBar2, wxAuiPaneInfo()
                                      .ToolbarPane()
                                      .Top()
                                      .Caption("Extra toolbar")
                                      .CloseButton(false)
                                      .Row(1));
    auiManager->Update();

    gauge->SetValue(50);
    for (int i = 1; i <= 10; ++i) {
      choice->Append("item " + std::to_string(i));
    }
    choice->SetSelection(0);
    choice->Bind(wxEVT_CHOICE, [&](wxCommandEvent &e) {
      listBox1->Append(
          wxString::Format("Choose item : %s", choice->GetStringSelection()));
    });
  }

private:
  wxListBox *listBox1 = new wxListBox(this, wxID_ANY);
  wxAuiManager *auiManager = new wxAuiManager(this);
  wxAuiToolBar *toolBar1 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition,
                                            wxDefaultSize, wxAUI_TB_GRIPPER);
  wxAuiToolBar *toolBar2 = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition,
                                            wxDefaultSize, wxAUI_TB_GRIPPER);
  wxChoice *choice = new wxChoice(toolBar1, wxID_ANY);
  wxGauge *gauge = new wxGauge(toolBar2, wxID_ANY, 100, wxDefaultPosition,
                               {150, wxDefaultCoord});
};

class Application : public wxApp {
  bool OnInit() override {
    (new Frame())->Show();
    return true;
  }
};
} // namespace AuiToolbarExample

wxIMPLEMENT_APP(AuiToolbarExample::Application);
