#pragma once
#include <vector>
#include <string>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/event.h>

class wxDomainSpinCtrl : public wxPanel {
public:
  wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, winid, pos, size) {
    if (size == wxDefaultSize) this->SetSize(120, this->upDown.GetSize().GetHeight());

    this->textBox.SetPosition(wxPoint(0, 2));
    this->textBox.SetSize(this->GetSize() - wxSize(this->upDown.GetSize().GetWidth() + 2, 4));

    this->upDown.SetPosition(wxPoint(this->GetSize().GetWidth() - this->upDown.GetSize().GetWidth(), (this->GetSize().GetHeight() - this->upDown.GetSize().GetHeight()) / 2));
    this->upDown.SetRange(0, this->items.GetCount() - 1);
    this->upDown.Bind(wxEVT_SPIN, [&](wxSpinEvent& event) {
      this->SetTextWithSelectedIndex();
    });

    this->Bind(wxEVT_SIZE, [&](wxEvent& ev) {
      this->textBox.SetSize(this->GetSize() - wxSize(this->upDown.GetSize().GetWidth() + 2, 4));
      this->upDown.SetPosition(wxPoint(this->GetSize().GetWidth() - this->upDown.GetSize().GetWidth(), (this->GetSize().GetHeight() - this->upDown.GetSize().GetHeight()) / 2));
    });
  }

  wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, const wxArrayString& items) : wxDomainSpinCtrl(parent, winid, pos, size) {this->SetItems(items);}
  
  wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, const std::vector<wxString>& items) : wxDomainSpinCtrl(parent, winid, pos, size) {this->SetItems(items);}
  
  const wxArrayString& GetItems() const {return this->items;}
  
  wxArrayString& GetItems() {return this->items;}
  
  wxString GetValue() const {return this->textBox.GetValue();}

  void SetItems(const std::vector<wxString>& items) {
    this->items.clear();
    for(auto i : items)
      this->items.Add(i);
    this->upDown.SetRange(0, this->items.GetCount() - 1);
    this->SetTextWithSelectedIndex();
  }
  
  void SetItems(const wxArrayString& items) {
    this->items = items;
    this->SetTextWithSelectedIndex();
  }

  void SetSelectedIndex(size_t index) {
    this->upDown.SetValue(items.GetCount() - 1 - index);
    this->SetTextWithSelectedIndex();
  }
  
  void SetValue(const wxString& value) {this->textBox.SetValue(value);}

private:
  void SetTextWithSelectedIndex() {
    if (this->upDown.GetValue() < items.GetCount())
      this->textBox.SetValue(this->items[items.GetCount() - 1 - this->upDown.GetValue()]);
  }
  
  wxTextCtrl textBox {this, wxID_ANY};
  wxSpinButton upDown {this, wxID_ANY};
  wxArrayString items;
};
