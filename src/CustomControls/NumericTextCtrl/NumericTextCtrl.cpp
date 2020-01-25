#include <wx/wx.h>

namespace Examples {
  wxDEFINE_EVENT(wxEVT_VALUE, wxCommandEvent);

  class wxNumericTextCtrl : public wxTextCtrl {
  public:
    wxNumericTextCtrl(wxWindow* parent, wxWindowID id, double value = .0, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator,  const wxString& name = wxTextCtrlNameStr) : wxTextCtrl(parent, id, wxString::Format("%g", value), pos, size, style, validator, name)  {
      Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
        event.Skip((std::isdigit(event.GetUnicodeKey()) || event.GetUnicodeKey() == '.') && (event.GetUnicodeKey() != '.' || GetValue().Find('.') == std::string::npos));
      });
      
      Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
        wxQueueEvent(this, new wxCommandEvent(wxEVT_VALUE));
      });
    }
    
    double GetNumericValue() const {
      auto value = .0;
      wxTextCtrl::GetValue().ToCDouble(&value);
      return value;
    }
    
    void SetNumericValue(double value) {wxTextCtrl::SetValue(wxString::Format("%g", value));}
    
  private:
    using wxTextCtrl::GetValue;
    using wxTextCtrl::SetValue;
  };

  class Frame : public wxFrame {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "NumericTextBox example", wxDefaultPosition, {300, 300}) {
      numericTextBox1->Bind(wxEVT_VALUE, [&](wxCommandEvent& e) {
        std::cout << wxString::Format("ValueChanged [Value==%g]", numericTextBox1->GetNumericValue()) << std::endl;
      });
    }
    
  private:
    wxPanel* panel = new wxPanel(this);
    wxNumericTextCtrl* numericTextBox1 = new wxNumericTextCtrl(panel, wxID_ANY, 42.2, {10, 10});
  };

  class Application : public wxApp {
    bool OnInit() override {
      (new Frame())->Show();
      return true;
    }
  };
}

wxIMPLEMENT_APP(Examples::Application);
