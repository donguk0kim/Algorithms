#include "frog.hpp"
#include "debugger.hpp"
#include "fibonacci.hpp"
#include "super_frog.hpp"

int main() {
  
  // test case - Fibonacci Top Down
  sprint("test case - Fibonacci Top Down");
  Fibonacci fibonacci1;
  print(fibonacci1.top_down(1));
  print(fibonacci1.top_down(2));
  print(fibonacci1.top_down(3));
  print(fibonacci1.top_down(4));
  print(fibonacci1.top_down(5));
  sprint("");
  
  // test case - Fibonacci Bottom Up
  sprint("test case - Fibonacci Bottom Up");
  Fibonacci fibonacci2;
  print(fibonacci2.bottom_up(1));
  print(fibonacci2.bottom_up(2));
  print(fibonacci2.bottom_up(3));
  print(fibonacci2.bottom_up(4));
  print(fibonacci2.bottom_up(5));
  sprint("");
  
  // test case - Frog Top Down
  sprint("test case - Frog Top Down");
  Frog frog1;
  vvprint(frog1.top_down(1));
  vvprint(frog1.top_down(2));
  vvprint(frog1.top_down(3));
  vvprint(frog1.top_down(4));
  sprint("");
  
  // test case - Frog Bottom Up
  sprint("test case - Frog Bottom Up");
  Frog frog2;
  vvprint(frog2.bottom_up(1));
  vvprint(frog2.bottom_up(2));
  vvprint(frog2.bottom_up(3));
  vvprint(frog2.bottom_up(4));
  sprint("");
  
  return 0;
}
