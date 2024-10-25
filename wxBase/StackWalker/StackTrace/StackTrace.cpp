#include <wx/crt.h>
#include <wx/init.h>
#include "StackTrace.h"

void method3() {
  wxPrintf("Stack Trace :\n");
  auto stack = wxStackTrace {true};
  wxPrintf("%s", stack.ToString());
}

void method2() {
  method3();
}

void method1() {
  method2();
}

auto main()->int {
  auto initializer = wxInitializer {};
  method1();
}

// This example can show the following output :
// Stack Trace :
//    at method3() [0x00000000] in StackTrace.cpp:line 7
//    at method2() [0x00000000] in StackTrace.cpp:line 12
//    at method1() [0x00000000] in StackTrace.cpp:line 16
//    at main [0x00000000] in StackTrace.cpp:line 21
//    at start [0x00000000] in :line 0
