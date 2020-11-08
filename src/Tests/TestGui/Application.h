#pragma once
#include <stdexcept>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication() : wxApplication(nullptr, true, substituteArgc, nullptr) {}
  wxApplication(wxApplication* app) : wxApplication(app, true, substituteArgc, nullptr) {}
  wxApplication(bool exit_on_last_frame_closed) : wxApplication(nullptr, exit_on_last_frame_closed, substituteArgc, nullptr) {}
  wxApplication(wxApplication* app, bool exit_on_last_frame_closed) : wxApplication(app, exit_on_last_frame_closed, substituteArgc, nullptr) {}
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
    auto menubar = new wxMenuBar();
    menubar->Bind(wxEVT_MENU, [&](wxCommandEvent& event) {
      if (event.GetId() == wxID_EXIT) {
        auto can_quit = true;
        for (auto window : wxTopLevelWindows)
          if (!(can_quit = window->Close())) break;
        if (can_quit) ExitMainLoop();
      } else event.Skip();
    });
#if __APPLE__
    wxMenuBar::MacSetCommonMenuBar(menubar);
#endif
  }
  
  ~wxApplication() {
    wxImage::CleanUpHandlers();
    wxApp::SetInstance(nullptr);
    wxEntryCleanup();
  }
  
  bool OnExceptionInMainLoop() override {
    exceptionStored = std::current_exception();
    return false;
  }

  int MainLoop() override {
    struct CallOnExit {
      ~CallOnExit() {
        wxTheApp->OnExit();
      }
    } callOnExit;
    auto result = wxApp::MainLoop();
    if (exceptionStored) std::rethrow_exception(exceptionStored);
    return result;
  }
  
private:
  int substituteArgc = 0;
  std::exception_ptr exceptionStored;
};
