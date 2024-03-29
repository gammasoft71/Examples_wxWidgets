#pragma once
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication(bool exitOnLastFrameClosed = true, wxLogLevelValues logLevel = wxLogLevelValues::wxLOG_Max) : wxApplication {exitOnLastFrameClosed, logLevel, substituteArgc, nullptr} {}
  wxApplication(int& argc, char** argv) : wxApplication {true, wxLogLevelValues::wxLOG_Max, argc, argv} {}
  wxApplication(bool exitOnLastFrameClosed, wxLogLevelValues logLevel, int& argc, char** argv) {
#ifdef _MSC_VER
    _CrtSetDbgFlag(_CRTDBG_CHECK_DEFAULT_DF);
#endif
    wxDISABLE_DEBUG_SUPPORT();
    wxSetAssertHandler(&NewAssertHandler);
    wxLog::SetLogLevel(logLevel);
    wxSystemOptions::SetOption("gtk.tlw.can-set-transparent", 1);
    wxSystemOptions::SetOption("osx.openfiledialog.always-show-types", 1);
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
  
  bool AssertEnabled() const noexcept {return assertEnabled;}
  void AssertEnabled(bool enabled) noexcept {assertEnabled = enabled;}

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
