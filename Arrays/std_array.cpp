#include <iostream>
#include <array>
/* The first element in the template is the type,the second element is the size
that MUST be constant. You can have the compiler that will deduce it
automatically.
*/
int main() {
  int const size = 3;
  std::array<int, size> arr{1, 2, 3};
  std::array array{2, 3, 4};
}