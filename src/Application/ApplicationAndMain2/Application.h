#pragma once
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication() : wxApplication(nullptr, true, argc_, nullptr) {}
  wxApplication(wxApplication* app) : wxApplication(app, true, argc_, nullptr) {}
  wxApplication(bool exit_on_last_frame_closed) : wxApplication(nullptr, exit_on_last_frame_closed, argc_, nullptr) {}
  wxApplication(wxApplication* app, bool exit_on_last_frame_closed) : wxApplication(app, exit_on_last_frame_closed, argc_, nullptr) {}
  wxApplication(int& argc, char** argv) : wxApplication(nullptr, true, argc, argv) {}
  wxApplication(wxApplication* app, int& argc, char** argv) : wxApplication(app, true, argc, argv) {}
  wxApplication(bool exit_on_last_frame_closed, int& argc, char** argv) : wxApplication(nullptr, exit_on_last_frame_closed, argc, argv) {}
  wxApplication(wxApplication* app, bool exit_on_last_frame_closed, int& argc, char** argv) {
    wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
    wxApp::SetInstance(app ? app : this);
    wxEntryStart(argc, argv);
    CallOnInit();
    SetExitOnFrameDelete(exit_on_last_frame_closed);
    wxInitAllImageHandlers();
#if __WXOSX__
    auto menubar = new wxMenuBar();
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_EXIT) {
        auto can_quit = true;
        for (auto window : wxTopLevelWindows)
          if (!(can_quit = window->Close())) break;
        if (can_quit) ExitMainLoop();
      } else event.Skip();
    });
    wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
  }
  
  ~wxApplication() {
    wxImage::CleanUpHandlers();
    wxApp::SetInstance(nullptr);
    wxEntryCleanup();
  }
  
  int MainLoop() override {
    struct CallOnExit {
      ~CallOnExit() {wxTheApp->OnExit();}
    } callOnExit;
    return wxApp::MainLoop();
  }
  
private:
  int argc_ = 0;
};
