#pragma once
#include <wx/app.h>
#include <wx/menu.h>

class wxApplication : public wxApp {
public:
  wxApplication(bool exitOnLastFrameClosed = true) : wxApplication(exitOnLastFrameClosed, substituteArgc, nullptr) {}
  wxApplication(int& argc, char** argv) : wxApplication(true, argc, argv) {}
  wxApplication(bool exitOnLastFrameClosed, int& argc, char** argv) {
    wxDISABLE_DEBUG_SUPPORT();
    wxApp::SetInstance(this);
    wxEntryStart(argc, argv);
#if defined(__APPLE__)
    static auto init = false; // Workaround : On macOS, call only one wxApp::CallOnInit because after calling wxApp::CleanUp, calling wxApp::CallOnInit again is blocking...
    if (!init) CallOnInit();
    init = true;
    wxMenuBar::MacSetCommonMenuBar(CreateDefaultMenuBar());
#else
    CallOnInit();
#endif
    SetExitOnFrameDelete(exitOnLastFrameClosed);
    wxInitAllImageHandlers();
  }

  ~wxApplication() {
#if defined(__APPLE__)
    delete wxMenuBar::MacGetCommonMenuBar();
#endif
    wxImage::CleanUpHandlers();
    CleanUp();
    SetInstance(nullptr);
  }

  int MainLoop(wxWindow* window) {
    struct CallOnExit {
      ~CallOnExit() {wxTheApp->OnExit();}
    } callOnExit;
    if (window) window->Show();
    return wxApp::MainLoop();
  }
  int MainLoop() override {return MainLoop(GetTopWindow());}

private:
  static wxMenuBar* CreateDefaultMenuBar() {
    auto menubar = new wxMenuBar;
    menubar->Bind(wxEVT_MENU, &OnMenuClick);
    return menubar;
  }
  
  static void OnMenuClick(wxCommandEvent& event) {
    if (event.GetId() != wxID_EXIT) {
      auto canExit = true;
      for (auto window : wxTopLevelWindows)
        if (!(canExit = window->Close())) break;
      if (canExit) wxTheApp->ExitMainLoop();
    } else event.Skip();
  }
  
  int substituteArgc = 0;
};
