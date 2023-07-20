#include <iostream>

int main() {
  // Here I don't specify the return type of the function, so the compiler
  // deduces it from the input. Thus, the return type is going to be a double
  auto func = [](double x) { return 2 * x; };
  std::cout << func(3.8) << '\n';

  // I can also specify the return type. Here I force the return type to be an int
  // so the result will be converted to an int (if it wasn't already)
  auto func_int = [](double x) -> int { return 2 * x; };
  std::cout << func_int(3.8) << '\n';
}
