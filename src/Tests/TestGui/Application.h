#pragma once
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication() : wxApplication(nullptr, true) {}
  wxApplication(wxApplication* app) : wxApplication(app, true) {}
  wxApplication(bool exit_on_last_frame_closed) : wxApplication(nullptr, exit_on_last_frame_closed) {}
  wxApplication(wxApplication* app, bool exit_on_last_frame_closed) {
    wxDISABLE_DEBUG_SUPPORT();
    wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
    wxApp::SetInstance(app ? app : this);
    auto argc = 0;
    wxEntryStart(argc, (wxChar**)NULL);
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
    OnExit();
    wxApp::SetInstance(nullptr);
    wxEntryCleanup();
  }
  
  int MainLoop() override {return wxApp::MainLoop();}
};
