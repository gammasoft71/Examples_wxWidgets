#include "Console.h"
#include <wx/wx.h>

using namespace std;

int main(int argc, char* argv[]) {
  auto console = new wxConsole;
  cout << wxString::Format("%s", "Hello, World!") << endl;
}
