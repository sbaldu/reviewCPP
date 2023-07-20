
#include <iostream>

template <typename T1, typename T2>
T1 max(T1 arg1, T2 arg2) {
  if (arg1 > arg2) {
    return arg1;
  } else {
    return arg2;
  }
}

template <typename T1, typename T2, typename... Tn>
T1 max(T1 arg1, T2 arg2, Tn... args) {
  if (arg1 > arg2) {
    return max(arg1, args...);
  } else {
    return max(arg2, args...);
  }
}

int main() { std::cout << max(2, 3, 0, 9, 4) << std::endl; }
