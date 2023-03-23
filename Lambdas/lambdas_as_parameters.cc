#include <iostream>
#include <functional>

using func_t = std::function<int(int)>;

int pow2(int val) { return val*val; }

int applyWithParameter(int value, func_t function) {
  return function(value);
}

// The template allows us to generalize the type of the function object and
// thus abstract the pass of said function
template <typename F>
int applyWithTemplate(int value, F f) {
  return f(value);
}

// Since C++20 you can use auto when defining function objects as parameters
int applyWithConst(int value, auto const& function) {
  return function(value);
} 

int main() {
  int val{5};

  // The baisc way is to specify the type of the function object and simply 
  // pass the function as any parameter
  std::cout << applyWithParameter(val, [](int x){ return x*x; }) << '\n';
  // Pass the type of the function object as template parameter
  // and the function as a lambda
  std::cout << applyWithTemplate<func_t>(val, [](int x){ return x*x; }) << '\n';

  // Template argument deduction
  std::cout << applyWithTemplate(val, [](int x){ return x*x; }) << '\n';

  // Using const
  std::cout << applyWithConst(val, [](int x){ return x*x; }) << '\n';
}
