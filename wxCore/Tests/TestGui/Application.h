#pragma once
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication(bool exitOnLastFrameClosed = true) : wxApplication(exitOnLastFrameClosed, substituteArgc, nullptr) {}
  wxApplication(int& argc, char** argv) : wxApplication(true, argc, argv) {}
  wxApplication(bool exitOnLastFrameClosed, int& argc, char** argv) {
#ifdef _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_CHECK_DEFAULT_DF);
#endif
    wxDISABLE_DEBUG_SUPPORT();
    wxSetAssertHandler(&NewAssertHandler);
    wxLog::SetLogLevel(wxLOG_Info);
    wxSystemOptions::SetOption("gtk.tlw.can-set-transparent", 1);
    wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
    wxApp::SetInstance(this);
    wxEntryStart(argc, argv);
    CallOnInit();
    SetExitOnFrameDelete(exitOnLastFrameClosed);
    wxInitAllImageHandlers();
#if defined(__APPLE__)
    wxMenuBar::MacSetCommonMenuBar(CreateDefaultMenuBar());
#endif
  }
  
  bool AssertEnabled() {return assertEnabled;}
  void AssertEnabled(bool enabled) {assertEnabled = enabled;}

  int MainLoop(wxWindow* window) {
    struct CallOnExit {
      ~CallOnExit() {wxTheApp->OnExit();}
    } callOnExit;
    if (window) window->Show();
    return wxApp::MainLoop();
  }
  int MainLoop() override {return MainLoop(GetTopWindow());}
  
  static wxMenuBar* CreateDefaultMenuBar() {
    wxMenuBar* menubar = new wxMenuBar();
    menubar->Bind(wxEVT_MENU, &OnMenuClick);
    return menubar;
  }
  
protected:
  int OnExit() override {
    wxImage::CleanUpHandlers();
    wxEntryCleanup();
    wxApp::SetInstance(nullptr);
    return wxApp::OnExit();
  }
  
private:
  static void OnMenuClick(wxCommandEvent& event) {
    if (event.GetId() == wxID_EXIT) {
      auto canExit = true;
      for (auto window : wxTopLevelWindows)
        if (!(canExit = window->Close())) break;
      if (canExit) wxTheApp->ExitMainLoop();
    } else event.Skip();
  }

  static void NewAssertHandler(const wxString& file, int line, const wxString& func, const wxString& cond, const wxString& msg) {
    if (!assertEnabled) return;
    wxMessageOutputDebug().Output("wxAssert");
    wxMessageOutputDebug().Output("--------");
    wxMessageOutputDebug().Printf("cond=%s, msg=%s", cond, msg);
    wxMessageOutputDebug().Printf("  at %s in %s:line %d", func, file, line);
  }
  
  inline static bool assertEnabled = false;
  int substituteArgc = 0;
};
