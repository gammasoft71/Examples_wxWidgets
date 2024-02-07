#pragma once
#include <vector>
#include <string>
#include <wx/event.h>
#include <wx/panel.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>

class wxDomainSpinCtrl : public wxPanel {
public:
  wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize) : wxPanel(parent, winid, pos, size) {
    if (size == wxDefaultSize) SetSize(120, textBox->GetSize().GetHeight());

    textBox->SetPosition(wxPoint(0, 0));
    textBox->SetSize(GetSize() - wxSize(upDown->GetSize().GetWidth() + 2, 0));

    upDown->SetPosition(wxPoint(GetSize().GetWidth() - upDown->GetSize().GetWidth(), 0));
    upDown->SetSize(upDown->GetSize().GetWidth(), GetSize().GetHeight());
    upDown->SetRange(0, static_cast<int>(items.size()) - 1);
    upDown->Bind(wxEVT_SPIN, [&](wxSpinEvent& event) {
      SetTextWithSelectedIndex();
    });

    Bind(wxEVT_SIZE, [&](wxEvent& ev) {
      textBox->SetSize(GetSize() - wxSize(upDown->GetSize().GetWidth() + 2, 0));
      upDown->SetPosition(wxPoint(GetSize().GetWidth() - upDown->GetSize().GetWidth(), (GetSize().GetHeight() - upDown->GetSize().GetHeight()) / 2));
    });
  }

  wxDomainSpinCtrl(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, const std::vector<wxString>& items) : wxDomainSpinCtrl(parent, winid, pos, size) { SetItems(items); }

  const std::vector<wxString>& GetItems() const { return items; }

  std::vector<wxString>& GetItems() { return items; }

  wxString GetValue() const { return textBox->GetValue(); }

  template<typename char_t>
  void SetItems(const std::vector<const char_t*>& items) {
    this->items.clear();
    for (auto i : items)
      this->items.push_back(i);
    upDown->SetRange(0, static_cast<int>(this->items.size()) - 1);
    SetTextWithSelectedIndex();
  }
  
  void SetItems(const std::vector<wxString>& items) {
    this->items = items;
    upDown->SetRange(0, static_cast<int>(this->items.size()) - 1);
    SetTextWithSelectedIndex();
  }

  void SetSelectedIndex(size_t index) {
    upDown->SetValue(static_cast<int>(items.size() - 1 - index));
    SetTextWithSelectedIndex();
  }

  void SetValue(const wxString& value) { textBox->SetValue(value); }

private:
  void SetTextWithSelectedIndex() {
    if (upDown->GetValue() < items.size())
      textBox->SetValue(items[items.size() - 1 - upDown->GetValue()]);
    wxCommandEvent event(wxEVT_TEXT, this->GetId());
    GetEventHandler()->ProcessEvent(event);
  }

  wxTextCtrl* textBox = new wxTextCtrl(this, wxID_ANY);
  wxSpinButton* upDown = new wxSpinButton(this, wxID_ANY);
  std::vector<wxString> items;
};
