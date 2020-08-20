#include <wx/wx.h>
#include <wx/filepicker.h>
#include <wx/sysopt.h>

// Workaround : with wxWidgets version <= 3.1.4 wxFilePickerCtrl::SetFilterIndex doesn't work on macOS
class FilePickerCtrl : public wxFilePickerCtrl {
public:
  FilePickerCtrl(wxWindow *parent, wxWindowID id, const wxString& path = wxEmptyString, const wxString& message = wxFileSelectorPromptStr, const wxString& wildcard = wxFileSelectorDefaultWildcardStr, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxFLP_DEFAULT_STYLE, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxFilePickerCtrlNameStr) : wxFilePickerCtrl(parent, id, path, message, wildcard, pos, size, style, validator, name) {
    auto pickerCtrl = GetPickerCtrl();
    auto wx_dialog_style = 0;
    if ((style & wxFLP_OPEN) == wxFLP_OPEN) wx_dialog_style |= wxFD_OPEN;
    if ((style & wxFLP_SAVE) == wxFLP_SAVE) wx_dialog_style |= wxFD_SAVE;
    if ((style & wxFLP_OVERWRITE_PROMPT) == wxFLP_OVERWRITE_PROMPT) wx_dialog_style |= wxFD_OVERWRITE_PROMPT;
    if ((style & wxFLP_FILE_MUST_EXIST) == wxFLP_FILE_MUST_EXIST) wx_dialog_style |= wxFD_FILE_MUST_EXIST;
    if ((style & wxFLP_CHANGE_DIR) == wxFLP_CHANGE_DIR) wx_dialog_style |= wxFD_CHANGE_DIR;
    pickerCtrl->Bind(wxEVT_BUTTON, [=](wxCommandEvent& event) {
      wxFileDialog openFileDialog(parent, message, path, wxEmptyString, wildcard, wx_dialog_style);
      openFileDialog.SetFilterIndex(0);
      if (openFileDialog.ShowModal() == wxID_OK) {
        SetPath(openFileDialog.GetPath());
        wxPostEvent(this, wxFileDirPickerEvent(wxEVT_FILEPICKER_CHANGED, this, id, GetPath()));
      }
    });
  }
};

namespace Examples {
  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "FilePickerCtrl example", wxDefaultPosition, {300, 300}) {
      picker->Bind(wxEVT_FILEPICKER_CHANGED, [&](wxFileDirPickerEvent& event) {
        label->SetLabel(wxString::Format("File = %s", picker->GetPath()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxStaticText* label = new wxStaticText(panel, wxID_ANY, "File = ", wxPoint(10, 50));
    //wxFilePickerCtrl* picker = new wxFilePickerCtrl(panel, wxID_ANY, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", {10, 10}, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_SMALL);
    FilePickerCtrl* picker = new FilePickerCtrl(panel, wxID_ANY, wxEmptyString, wxEmptyString, "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", {10, 10}, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_SMALL);
  };

  class Application : public wxApp {
    bool OnInit() override {
      wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
