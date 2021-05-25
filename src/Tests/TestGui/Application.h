#pragma once
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication(bool exitOnLastFrameClosed = true) : wxApplication(exitOnLastFrameClosed, substituteArgc, nullptr) {}
  wxApplication(int& argc, char** argv) : wxApplication(true, argc, argv) {}
  wxApplication(bool exitOnLastFrameClosed, int& argc, char** argv) {
    wxApp::SetInstance(this);
    wxEntryStart(argc, argv);
    CallOnInit();
    SetExitOnFrameDelete(exitOnLastFrameClosed);
    wxInitAllImageHandlers();
    menubar = new wxMenuBar();
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_EXIT) {
        auto canExit = true;
        for (auto window : wxTopLevelWindows)
          if (!(canExit = window->Close())) break;
        if (canExit) ExitMainLoop();
      } else event.Skip();
    });
#if __APPLE__
    wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
  }
  
  int MainLoop(wxWindow* window) {
    struct CallOnExit {
      ~CallOnExit() {wxTheApp->OnExit();}
    } callOnExit;
    if (window) window->Show();
    return wxApp::MainLoop();
  }
  
  int MainLoop() override {return MainLoop(GetTopWindow());}
  
protected:
  int OnExit() override {
    delete menubar;
    wxImage::CleanUpHandlers();
    wxEntryCleanup();
    wxApp::SetInstance(nullptr);
    return wxApp::OnExit();
  }
  
private:
  int substituteArgc = 0;
  wxMenuBar* menubar = nullptr;
};
