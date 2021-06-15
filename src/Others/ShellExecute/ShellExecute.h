#include <filesystem>
#include <map>
#include <wx/string.h>
#include <wx/utils.h>

#if __WXMSW__
#include <Windows.h>
long wxShellExecute(const wxString& command, const wxString& arguments = wxEmptyString, const wxString& workingDirectory = wxEmptyString) {
  return ShellExecute(nullptr, nullptr, command.wc_str(), arguments.wc_str(), workingDirectory != wxEmptyString ? workingDirectory.wc_str() : nullptr, SW_NORMAL) > 32 ? return 0 : -1;
}
#else
long wxShellExecute(const wxString& command, const wxString& arguments = wxEmptyString, const wxString& workingDirectory = wxEmptyString) {
  if (workingDirectory != wxEmptyString) {
    class ChangeWorkingDirectory {
    public:
      ChangeWorkingDirectory(const wxString& workingDirectory) {
        currentDirectory = std::filesystem::current_path();
        std::filesystem::current_path(workingDirectory.ToStdString());
      }
      ~ChangeWorkingDirectory() {std::filesystem::current_path(currentDirectory);}
    private:
      std::filesystem::path currentDirectory;
    } changeWorkingDirectory {workingDirectory};
  }

  std::function<bool(const wxString& command)> IsKnownUri = [](const wxString& command)->bool {
    static std::vector<wxString> schemes = {"file", "ftp", "gopher", "http", "https", "mailto", "net.pipe", "net.tcp", "news", "nntp"};
    for (auto scheme : schemes) 
      if (command.find(scheme + ":") == 0) return true;
    return false;
  };
  std::function<bool(const wxString& command)> IsValidShellExecuteProcess = [&](const wxString& command)->bool {
    return command == wxEmptyString || std::filesystem::exists(command.ToStdString()) || IsKnownUri(command);
  };
  std::function<wxString()> ShellExecute = []()->wxString {
    static std::map<wxString, wxString> shellEecutes {{"Macintosh", "open "}, {"Unix", "xdg-opoen "}};
    auto it = shellEecutes.find(wxPlatformInfo::Get().GetOperatingSystemFamilyName());
    if (it == shellEecutes.end()) return "";
    return it->second;
  };
  
  wxString shellExecuteCommand = command;
  if (IsValidShellExecuteProcess(command)) shellExecuteCommand = wxString::Format("%s%s", ShellExecute(), command != wxEmptyString ? command : std::filesystem::current_path().string());
  return wxExecute(wxString::Format("%s%s", shellExecuteCommand, arguments != wxEmptyString ? wxString::Format(" %s", arguments) : ""));
}
#endif
