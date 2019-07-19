#include <wx/wx.h>

wxDEFINE_EVENT(wxEVT_VALUE, wxCommandEvent);

class wxNumericTextCtrl : public wxTextCtrl {
public:
  wxNumericTextCtrl(wxWindow* parent, wxWindowID id, double value = 0.0, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator,  const wxString& name = wxTextCtrlNameStr) : wxTextCtrl(parent, id, wxString::Format("%g", value), pos, size, style, validator, name)  {
    this->Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
      event.Skip((std::isdigit(event.GetUnicodeKey()) || event.GetUnicodeKey() == '.') && (event.GetUnicodeKey() != '.' || this->GetValue().Find('.') == std::string::npos));
    });
    
    this->Bind(wxEVT_TEXT, [&](wxCommandEvent& event) {
      wxQueueEvent(this, new wxCommandEvent(wxEVT_VALUE));
    });
  }
  
  double GetNumericValue() const {
    double value = 0.0;
    this->wxTextCtrl::GetValue().ToCDouble(&value);
    return value;
  }
  
  void SetNumericValue(double value) {this->wxTextCtrl::SetValue(wxString::Format("%g", value));}
  
private:
  using wxTextCtrl::GetValue;
  using wxTextCtrl::SetValue;
};

class Form : public wxFrame {
public:
  Form() : wxFrame(nullptr, wxID_ANY, "NumericTextBox example", wxDefaultPosition, wxSize(300, 300)) {
    this->numericTextBox1->Bind(wxEVT_VALUE, [&](wxCommandEvent& e) {
      std::cout << wxString::Format("ValueChanged [Value==%g]", this->numericTextBox1->GetNumericValue()) << std::endl;
    });
  }
  
private:
  wxPanel* panel = new wxPanel(this);
  wxNumericTextCtrl* numericTextBox1 = new wxNumericTextCtrl(this->panel, wxID_ANY, 42.2, wxPoint(10, 10));
};

class Application : public wxApp {
  bool OnInit() override {return (new Form())->Show();}
};

wxIMPLEMENT_APP(Application);
