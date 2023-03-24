#include <iostream>

template <int n>
class factorial{
  public:
	static const unsigned long long value { n * factorial<n-1>::value };
};

template<>
class factorial<0>{
  public:
	static const unsigned long long value { 1 };
};

int main() {
  std::cout << factorial<60>::value << '\n';
}
