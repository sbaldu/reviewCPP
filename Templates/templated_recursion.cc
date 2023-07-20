#include <iostream>
#include <vector>

// We define a recursive function
// We write it as a template function because that way the number of recursions
// is known at compile time
template <int N>
void rec_function() {
  std::cout << "Partial output\n";
  rec_function<N - 1>();
}

// As in all recursive functions, we must provide the "zero" case
template <>
void rec_function<0>() {
  std::cout << "Done!\n";
}

// Now suppose that we want to do the same thing for a method inside a class
class myclass {
private:
  int m_x;

public:
  myclass(int x) : m_x{x} {}

  template <int N>
  void rec_method();
};

// The implementation is basically the same, but we have to declase the method inside the class scope
// and define it outside
template <int N>
void myclass::rec_method() {
  std::cout << m_x << '\n';
  rec_method<N - 1>();
}

template <>
void myclass::rec_method<0>() {
  std::cout << "Done!\n";
}

// What if the class is a class template?
// We can't define as we did with the normal class, because the definition of the default case
// would imply a partial specialization of a function template which is not allowed
template <int N>
class classtemplate {
private:
  int m_x;

public:
  classtemplate(int x) : m_x{x} {}

  template <int M>
  void rec_method() {
    if constexpr (M == 0) {      // Like this the default case is evaluated at compile time, which is
      std::cout << "Done!\n";    // what we want. If we didn't include the constexpr, the conditional
    } else {                     // statement would only be evaluated at run time, which means that
      std::cout << m_x << '\n';  // at compile time the recursive function has no default case and
      rec_method<M - 1>();       // goes on forever, causing a "exceeded maximum depth" error
    }
  }
};

int main() {
  // Test the recursive function
  rec_function<4>();

  // Instantiate an object of myclass and test the recursive method
  myclass m{5};
  m.rec_method<4>();

  classtemplate<5> ct{3};
  ct.rec_method<3>();
}
