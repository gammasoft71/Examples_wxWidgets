#include <wx/app.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/panel.h>

namespace NumericTextCtrlExample {
  wxDEFINE_EVENT(wxEVT_VALUE, wxCommandEvent);

  class wxNumericTextCtrl : public wxTextCtrl {
  public:
    wxNumericTextCtrl(wxWindow* parent, wxWindowID id, double value = .0, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator,  const wxString& name = wxTextCtrlNameStr) : wxTextCtrl {parent, id, wxString::FromDouble(value), pos, size, style, validator, name}  {
      Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
        event.Skip((iscntrl(event.GetUnicodeKey()) || isdigit(event.GetUnicodeKey()) || event.GetUnicodeKey() == '.') && (event.GetUnicodeKey() != '.' || GetValue().Find('.') == wxString::npos));
      });
      
      Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        wxQueueEvent(this, new wxCommandEvent {wxEVT_VALUE});
      });
    }
    
    double GetNumericValue() const {
      auto value = .0;
      wxTextCtrl::GetValue().ToDouble(&value);
      return value;
    }
    
    void SetNumericValue(double value) {wxTextCtrl::SetValue(wxString::FromDouble(value));}
    
  private:
    using wxTextCtrl::GetValue;
    using wxTextCtrl::SetValue;
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame {nullptr, wxID_ANY, "NumericTextBox example"} {
      numericTextBox1->Bind(wxEVT_VALUE, [&](wxCommandEvent& e) {
        wxMessageOutputDebug().Printf("ValueChanged [Value=%s]", wxString::FromDouble(numericTextBox1->GetNumericValue()));
      });
    }
    
  private:
    wxPanel* panel = new wxPanel {this};
    wxNumericTextCtrl* numericTextBox1 = new wxNumericTextCtrl {panel, wxID_ANY, 42.2, {10, 10}};
  };

  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(NumericTextCtrlExample::Application);
