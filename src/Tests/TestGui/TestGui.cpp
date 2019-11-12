#include "AppInitializer.h"
#include <wx/app.h>
#include <wx/button.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/filepicker.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/stdpaths.h>
#include <wx/stattext.h>

//#if defined(__WXOSX__)
#if defined(__WXGTK__)
class wxFilePicker : public wxFilePickerCtrl {
public:
  wxFilePicker(wxWindow* parent, wxWindowID id, const wxString& message = wxFileSelectorPromptStr, const wxString& defaultDir = wxEmptyString, const wxString& defaultFile = wxEmptyString, const wxString& wildCard = wxFileSelectorDefaultWildcardStr, const wxPoint& pos = wxDefaultPosition, const wxSize& size = {125, 21}, long style = wxFLP_OPEN | wxFLP_FILE_MUST_EXIST, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxButtonNameStr) : wxFilePickerCtrl(parent, id, wxEmptyString, message, wildCard, pos, size, style, validator, name), defaultDir_(defaultDir), defaultFile_(defaultFile) {
    SetInitialDirectory(defaultDir);
    SetFileName(defaultFile);
    Bind(wxEVT_FILEPICKER_CHANGED, [this](wxFileDirPickerEvent& event) {
        SetPath(event.GetPath());
    });
  }
  
  const wxString& GetPath() const {return path_;}
  void SetPath(const wxString& value) {
    if (path_ != value) {
      path_ = value;
      if (!path_.empty()) {
        wxFileName fn(path_);
        SetInitialDirectory(fn.GetPath());
        SetFileName( wxString::Format("%s.%s", fn.GetName(), fn.GetExt()));
      } else {
        SetInitialDirectory(defaultDir_);
        SetFileName(defaultFile_);
      }
      wxPostEvent(this, wxCommandEvent(wxEVT_TEXT, GetId()));
    }
  }

private:
  wxString defaultDir_;
  wxString defaultFile_;
  wxString path_;
};
#else
class wxFilePicker : public wxButton {
public:
  wxFilePicker(wxWindow* parent, wxWindowID id, const wxString& message = wxFileSelectorPromptStr, const wxString& defaultDir = wxEmptyString, const wxString& defaultFile = wxEmptyString, const wxString& wildCard = wxFileSelectorDefaultWildcardStr, const wxPoint& pos = wxDefaultPosition, const wxSize& size = {125, 21}, long style = wxFLP_OPEN | wxFLP_FILE_MUST_EXIST, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxButtonNameStr) : wxButton(parent, id, wxEmptyString, pos, size, wxBU_LEFT, validator, name), message_(message), defaultDir_(defaultDir), defaultFile_(defaultFile), wildCard_(wildCard), wx_style_(style) {
    SetBitmap(wxImage(file_picker_logo));
    SetBitmapPosition(wxDirection::wxRIGHT);
    SetLabel("(none)");
    
    Bind(wxEVT_BUTTON, [this](wxCommandEvent& event) {
      long dialog_style = 0;
      
      if ((wx_style_ & wxFLP_OPEN) == wxFLP_OPEN) dialog_style += wxFD_OPEN;
      if ((wx_style_ & wxFLP_OPEN) == wxFLP_SAVE) dialog_style += wxFD_SAVE;
      if ((wx_style_ & wxFLP_FILE_MUST_EXIST) == wxFLP_FILE_MUST_EXIST) dialog_style += wxFD_FILE_MUST_EXIST;
      if ((wx_style_ & wxFLP_OVERWRITE_PROMPT) == wxFLP_OVERWRITE_PROMPT) dialog_style += wxFD_OVERWRITE_PROMPT;

      wxFileDialog openFileDialog(this, message_, defaultDir_, defaultFile_, wildCard_, dialog_style);
      if (openFileDialog.ShowModal() == wxID_OK)
        SetPath(openFileDialog.GetPath());
    });
  }
  
  const wxString& GetPath() const {return path_;}
  void SetPath(const wxString& value) {
    if (path_ != value) {
      path_ = value;
      wxFileName fn(path_);
      SetLabel(path_.empty() ? "(none)" : wxString::Format("%s.%s", fn.GetName(), fn.GetExt()));
      wxPostEvent(this, wxCommandEvent(wxEVT_TEXT, GetId()));
    }
  }

private:
  static constexpr const char* file_picker_logo[] = {"17 15 173 2 ", "   c None", ".  c #434541", "X  c #484844", "o  c #514E45", "O  c #6A6252", "+  c #6F6453", "@  c #87785D", "#  c #8A795B", "$  c #8A795D", "%  c #8B7A5F", "&  c #8C7A5C", "*  c #877A64", "=  c #8A7B60", "-  c #897B63", ";  c #8A7C60", ":  c #8E7E63", ">  c #8A7C67", ",  c #958463", "<  c #9E8C6B", "1  c #9B8F72", "2  c #9E9074", "3  c #9D9278", "4  c #9F9278", "5  c #A28F6D", "6  c #A19377", "7  c #A99773", "8  c #AF9970", "9  c #AD9976", "0  c #A19379", "q  c #A1967C", "w  c #B59F78", "e  c #B7A176", "r  c #BDA67B", "t  c #BDA77E", "y  c #C0A87C", "u  c #C1A97D", "i  c #C0A87E", "p  c #C0A97E", "a  c #C1A97E", "s  c #C3AA7F", "d  c #9B988D", "f  c #9B988E", "g  c #979791", "h  c #989891", "j  c #989892", "k  c #989992", "l  c #999992", "z  c #A99E83", "x  c #ACA28C", "c  c #B8A88A", "v  c #BFAA89", "b  c #BAAB8F", "n  c #BBBFB8", "m  c #C0AB83", "M  c #C2AB82", "N  c #C4AB80", "B  c #C0A987", "V  c #C0AA87", "C  c #C2AD86", "Z  c #C3AD86", "A  c #C5AF86", "S  c #C3AD89", "D  c #C2AD8A", "F  c #C2AC8B", "G  c #C4AE8A", "H  c #C1AC8C", "J  c #C1AF8E", "K  c #C7B187", "L  c #C8B186", "P  c #C5B088", "I  c #C6B189", "U  c #C5B08B", "Y  c #C7B28A", "T  c #C7B18D", "R  c #C5B28D", "E  c #C4B18F", "W  c #C6B18F", "Q  c #C6B38E", "!  c #C6B48E", "~  c #C7B48F", "^  c #CAB289", "/  c #C8B28A", "(  c #CBB48A", ")  c #CBB48B", "_  c #CDB58B", "`  c #C9B28D", "'  c #C9B48E", "]  c #C9B48F", "[  c #CFB78D", "{  c #CFB78E", "}  c #D0B88E", "|  c #D2BA8F", " . c #C4B190", ".. c #C7B597", "X. c #C9B490", "o. c #C8B590", "O. c #C9B691", "+. c #CBB690", "@. c #CAB792", "#. c #C8B496", "$. c #C9B597", "%. c #C8B699", "&. c #D2BB90", "*. c #D3BB90", "=. c #D2BB92", "-. c #D3BC91", ";. c #D1BC94", ":. c #D1C09F", ">. c #D1C0A0", ",. c #D2C2A1", "<. c #DCC6A5", "1. c #DEC7A4", "2. c #DCC7A7", "3. c #DFC8A5", "4. c #D6C7AE", "5. c #DBC6A9", "6. c #DCC8AC", "7. c #DCCBAF", "8. c #E1CAA9", "9. c #E2CBAA", "0. c #E2CCAB", "q. c #E5CFAF", "w. c #E2CEB0", "e. c #E6CFB1", "r. c #E6CFB2", "t. c #E6D0B2", "y. c #E7D1B4", "u. c #E7D2B5", "i. c #E8D2B5", "p. c #E8D3B8", "a. c #E9D4B9", "s. c #E9D4BA", "d. c #EAD5BA", "f. c #E8D7BB", "g. c #EAD6BB", "h. c #EED9BF", "j. c #C6C7C3", "k. c #C4C8C1", "l. c #C5C9C2", "z. c #C8C9CA", "x. c #C8CACA", "c. c #CBCCCB", "v. c #CDCFD0", "b. c #D1D3D4", "n. c #D2D3D4", "m. c #EBDBC3", "M. c #EBDCC7", "N. c #EDDDC7", "B. c #E5DCCC", "V. c #ECDDC8", "C. c #ECDDC9", "Z. c #EDDFCB", "A. c #EBDECC", "S. c #EEE0CD", "D. c #EEE0CE", "F. c #EFE2D1", "G. c #EFE5D5", "H. c #E3E3DF", "J. c #E4E3DF", "K. c #F0E3D2", "L. c #F2E5D4", "P. c #F2E6D7", "I. c #F3E9D8", "U. c #E7E6E3", "Y. c #E7E7E4", "T. c #E8E7E4", "R. c #EEEEEC", "E. c #EEEFED", "W. c #F4F4F4", "Q. c #F6F6F6", "!. c #F9F8F6", "~. c #FBFBF9", "^. c #FEFEFE", "O 7 N i t i s < X                 ", "8 ;.,.:.:.:.:.+., .               ", "e -.O.I I ) ] ] M r i i s r i 5 o ", "e &.] A K M v C I R ~ ~ ~ ] @.) # ", "e &.] K c d g g k k k k h d b _ % ", "e &.] ) 6 x.^.W.Q.Q.Q.W.^.x.q [ # ", "e &.~ ) 1 n.E.n l.j.l.n E.b.2 } # ", "e &.] ) 2 c.~.U.U.U.Y.H.!.c.q [ $ ", "e | O._ 4 j.B.J ........$.E F ` : ", "e | R L z x 7.A.F.S.S.Z.Z.M.Z.5.% ", "r =. . .D 4.K.N.a.a.a.a.a.p.a.<.% ", "w g.I.G.L.L.m.i.u.u.u.u.u.i.a.<.- ", "9 w.m.r.i.t.t.r.r.t.r.t.r.r.a.5.$ ", "* J 8.9.9.9.9.9.9.9.9.9.9.0.3.v + ", "  * B A S S S S S S S S S C v -   "};
  wxString message_;
  wxString defaultDir_;
  wxString defaultFile_;
  wxString wildCard_;
  wxString path_;
  long wx_style_ = 0;
};
#endif

int main(int argc, char* argv[]) {
  AppInitializer appInitializer;
  wxFrame* frame1 = new wxFrame(nullptr, wxID_ANY, "TestGui", wxDefaultPosition, {400, 250});

  wxPanel* panelMain = new wxPanel(frame1);
 
  wxFilePicker* filePicker = new wxFilePicker(panelMain, wxID_ANY, wxEmptyString, wxStandardPaths::Get().GetDocumentsDir(), "", "Text Files (*.txt)|*.txt|All Files (*.*)|*.*", {10, 10});
  wxStaticText* staticText = new wxStaticText(panelMain, wxID_ANY, "File = ", {10, 50});

  filePicker->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
    staticText->SetLabel(wxString::Format("File = %s", filePicker->GetPath()));
  });
  
  wxButton* buttonClear = new wxButton(panelMain, wxID_ANY, "Clear", {140, 10});
  buttonClear->Bind(wxEVT_BUTTON, [&](wxCommandEvent& event) {
    filePicker->SetPath(wxEmptyString);
  });
  
  frame1->Show();

  wxTheApp->OnRun();
}
