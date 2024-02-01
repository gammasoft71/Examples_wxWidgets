#include "Console.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  auto console = new wxConsole;
  cout << wxString::Format("%s", "Hello, World!") << endl;
}
