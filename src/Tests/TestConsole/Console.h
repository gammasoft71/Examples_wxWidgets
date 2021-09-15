#pragma once
#include <wx/app.h>
#include <wx/image.h>

class wxConsole : protected wxApp {
public:
  wxConsole() : wxConsole(substituteArgc, nullptr) {}
  wxConsole(int& argc, char** argv) {
    wxDISABLE_DEBUG_SUPPORT();
    wxApp::SetInstance(this);
    wxEntryStart(argc, argv);
    CallOnInit();
    wxInitAllImageHandlers();
  }
  
protected:
  int OnExit() override {
    wxImage::CleanUpHandlers();
    wxEntryCleanup();
    wxApp::SetInstance(nullptr);
    return wxApp::OnExit();
  }
  
private:
  int substituteArgc = 0;
};
