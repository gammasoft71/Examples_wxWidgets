#pragma once
#include <stdexcept>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/sysopt.h>

class wxApplication : public wxApp {
public:
  wxApplication() : wxApplication(nullptr, true, substitute_argc_, nullptr) {}
  wxApplication(wxApplication* app) : wxApplication(app, true, substitute_argc_, nullptr) {}
  wxApplication(bool exit_on_last_frame_closed) : wxApplication(nullptr, exit_on_last_frame_closed, substitute_argc_, nullptr) {}
  wxApplication(wxApplication* app, bool exit_on_last_frame_closed) : wxApplication(app, exit_on_last_frame_closed, substitute_argc_, nullptr) {}
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
    menubar = new wxMenuBar();
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
  
  int MainLoop(wxWindow* window) {
    struct CallOnExit {
      ~CallOnExit() {wxTheApp->OnExit();}
    } callOnExit;
    if (window) window->Show();
    return wxApp::MainLoop();
  }
  
  int MainLoop() override {return MainLoop(GetTopWindow());}

protected:
  bool OnExceptionInMainLoop() override {
    try {
      throw;
    } catch(const std::exception& e) {
      wxFAIL_MSG(e.what());
    } catch(...) {
      wxFAIL_MSG("Unknown exception occured");
    }
    return true;
  }
  
  int OnExit() override {
    delete menubar;
    wxImage::CleanUpHandlers();
    wxEntryCleanup();
    wxApp::SetInstance(nullptr);
    return wxApp::OnExit();
  }

private:
  int substitute_argc_ = 0;
  wxMenuBar* menubar = nullptr;
};
