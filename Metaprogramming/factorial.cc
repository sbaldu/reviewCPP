#include <iostream>

unsigned long long factorial(int num) {
  if (num == 0) {
    return 1;
  } else {
    return num * factorial(num - 1);
  }
}

int main() { std::cout << factorial(20) << '\n'; }
