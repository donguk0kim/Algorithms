#include "Frog.hpp"
#include "debugger.hpp"
#include "Fibonacci.hpp"
#include "SuperFrog.hpp"

int main() {
  
  // test case - Fibonacci Top Down
  sprint("test case - Fibonacci Top Down");
  Fibonacci fibonacci1;
  print(fibonacci1.topDown(1));
  print(fibonacci1.topDown(2));
  print(fibonacci1.topDown(3));
  print(fibonacci1.topDown(4));
  print(fibonacci1.topDown(5));
  sprint("");
  
  // test case - Fibonacci Bottom Up
  sprint("test case - Fibonacci Bottom Up");
  Fibonacci fibonacci2;
  print(fibonacci2.bottomUp(1));
  print(fibonacci2.bottomUp(2));
  print(fibonacci2.bottomUp(3));
  print(fibonacci2.bottomUp(4));
  print(fibonacci2.bottomUp(5));
  sprint("");
  
  // test case - Frog Top Down
  sprint("test case - Frog Top Down");
  Frog frog1;
  vvprint(frog1.topDown(1));
  vvprint(frog1.topDown(2));
  vvprint(frog1.topDown(3));
  vvprint(frog1.topDown(4));
  sprint("");
  
  // test case - Frog Bottom Up
  sprint("test case - Frog Bottom Up");
  Frog frog2;
  vvprint(frog2.bottomUp(1));
  vvprint(frog2.bottomUp(2));
  vvprint(frog2.bottomUp(3));
  vvprint(frog2.bottomUp(4));
  sprint("");
  
  return 0;
}
