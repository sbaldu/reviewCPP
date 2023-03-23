#include <iostream>

template <typename T>
void func(T value) {
  std::cout << value << '\n';
}

int main() {
  // Define a lambda function that takes a number and doubles it
  // In order to make it generic, you write a templated lambda (C++20)
  auto doubled = [] <typename T> (T value) { return 2*value; };

  // Test doubled for some data types
  // Notice that you don't have to specify the template parameter
  std::cout << doubled(3) << '\n';
  std::cout << doubled(3.7) << '\n';
}
