#include <iostream>

int main() {
  // We define 
  auto func = [](int x) { ++x; return x; };
  std::cout << func(3) << '\n';

  int y{5};
  /* auto func_byval = [y]() { ++y; return y; }; */
  auto func_byref = [&y]() { ++y; return y; };
  std::cout << "Return of func_byref = " << func_byref() << '\n';

  auto func_mutable = [y]() mutable { ++y; return y; };
  std::cout << "Return of func_mutable = " << func_mutable() << std::endl;
}
