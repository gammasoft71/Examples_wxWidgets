#include <wx/app.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/frame.h>
#include <wx/display.h>
#include <wx/log.h>
#include <wx/panel.h>

namespace EvtHandlerFilterEventExample {
  class Frame : public wxFrame, public wxEventFilter {
  public:
    Frame() : wxFrame(nullptr, wxID_ANY, "Event handler add filter example") {
      logWindow->GetFrame()->SetSize(wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetLeft(), wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetTop() + wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() - wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() / 4, wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetWidth(), wxDisplay(wxDisplay::GetFromWindow(logWindow->GetFrame())).GetClientArea().GetHeight() / 4);
      wxEvtHandler::AddFilter(this);
      mainPanel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {wxLogDebug(wxString::Format("(Frame.Bind) wxEVT_LEFT_DOWN x=%d, y=%d", wxGetMousePosition().x, wxGetMousePosition().y));});
      panel->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {wxLogDebug(wxString::Format("(Panel.Bind) wxEVT_LEFT_DOWN x=%d, y=%d", wxGetMousePosition().x, wxGetMousePosition().y));});
      button->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {wxLogDebug(wxString::Format("(Button.Bind) wxEVT_LEFT_DOWN x=%d, y=%d", wxGetMousePosition().x, wxGetMousePosition().y));});
      skipButtonEventCheckBox->Bind(wxEVT_LEFT_DOWN, [&](wxMouseEvent& e) {
        wxLogDebug(wxString::Format("(CheckBox.Bind) wxEVT_LEFT_DOWN x=%d, y=%d", wxGetMousePosition().x, wxGetMousePosition().y));
        skipButtonEventCheckBox->SetValue(!skipButtonEventCheckBox->GetValue());
      });
    }
    
    ~Frame() {
      wxEvtHandler::RemoveFilter(this);
    }
    
  private:
    int FilterEvent(wxEvent& event) override {
      // Uncomment following line to see all messages (except those in the logWindow text box).
      //if (event.GetId() != logWindow->GetFrame()->GetChildren()[0]->GetId() && event.GetEventType() != wxEVT_UPDATE_UI && event.GetEventType() != wxEVT_IDLE) wxLogDebug(wxString::Format("wxEvent {type=%d, id=%d}", event.GetEventType(), event.GetId()));
      return skipButtonEventCheckBox->IsChecked() && event.GetEventType() == wxEVT_LEFT_DOWN &&  event.GetEventObject() == button ? Event_Ignore : Event_Skip;
    }
    
    wxLogWindow* logWindow = new wxLogWindow(nullptr, "Debug");
    wxPanel* mainPanel = new wxPanel {this};
    wxPanel* panel = new wxPanel {mainPanel, wxID_ANY, {10, 10}, {200, 100}, wxTAB_TRAVERSAL|wxBORDER_SIMPLE};
    wxButton* button = new wxButton {panel, wxID_ANY, "Click me", {10, 10}};
    wxCheckBox* skipButtonEventCheckBox = new wxCheckBox {panel, wxID_ANY, "Skip button left up event", {10, 40}};
  };
  
  class Application : public wxApp {
    bool OnInit() override {return (new Frame)->Show();}
  };
}

wxIMPLEMENT_APP(EvtHandlerFilterEventExample::Application);
