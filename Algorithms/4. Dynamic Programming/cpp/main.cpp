#include "debugger.hpp"
#include "fibonacci.hpp"
#include "frog.hpp"
#include "super_frog.hpp"

int main() {

  // test case - Fibonacci Top Down
  Sprint("test case - Fibonacci Top Down");
  Fibonacci fibonacci1;
  Print(fibonacci1.TopDown(1));
  Print(fibonacci1.TopDown(2));
  Print(fibonacci1.TopDown(3));
  Print(fibonacci1.TopDown(4));
  Print(fibonacci1.TopDown(5));
  Sprint("");

  // test case - Fibonacci Bottom Up
  Sprint("test case - Fibonacci Bottom Up");
  Fibonacci fibonacci2;
  Print(fibonacci2.BottomUp(1));
  Print(fibonacci2.BottomUp(2));
  Print(fibonacci2.BottomUp(3));
  Print(fibonacci2.BottomUp(4));
  Print(fibonacci2.BottomUp(5));
  Sprint("");

  // test case - Frog Top Down
  Sprint("test case - Frog Top Down");
  Frog frog1;
  Vvprint(frog1.TopDown(1));
  Vvprint(frog1.TopDown(2));
  Vvprint(frog1.TopDown(3));
  Vvprint(frog1.TopDown(4));
  Sprint("");

  // test case - Frog Bottom Up
  Sprint("test case - Frog Bottom Up");
  Frog frog2;
  Vvprint(frog2.BottomUp(1));
  Vvprint(frog2.BottomUp(2));
  Vvprint(frog2.BottomUp(3));
  Vvprint(frog2.BottomUp(4));
  Sprint("");

  return 0;
}
