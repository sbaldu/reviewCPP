#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// We define the default template, which takes exactly one parameter
template <typename T1>
void newPrint(T1 arg1) {
  std::cout << "patata\n";
}

// We then define the generic case, which takes one parameter and a parameter pack
template <typename T1, typename... types>  // Equivalent to template <typename T1, typename T2, ...>
void newPrint(T1 arg1, types... args) {    // Equivalent to void print(T1 arg1, T2 arg2, ...)
  std::cout << "mortadella\n";
  newPrint(args...);  // Equivalent to print(arg1, arg2, ...)
}

// We can now use this concept to construct a class which defines a print method that takes any number
// of arguments and of any types. Using template template parameters we can also handle the case of
// types with no default print
class printer {
public:
  // We could define a handling function for every type, but of course the smarter thing to do would be
  // to use templates for the types with default prints, and then handle in separate methods the other
  // types
  template <typename T>
  void handlePrint(T value) {
    std::cout << value << '\n';
  }

  // For example we write a handling function for a generic container
  template <typename T, template <typename E, typename Allocator = std::allocator<E>> typename container = std::vector>
  void handlePrint(container<T>&& cont) {
    for (auto const& element : cont) {
      std::cout << element << '\n';
    }
  }

  // Then you define print as a recursive function that takes one argument at a time, handles it, and 
  // subsequently calls itself passing the remaining arguments
  template <typename T1, typename... Tn>
  void print(T1&& arg1, Tn&&... args) { 	// We use forwarding references because the type of the object
    handlePrint(std::forward<T1>(arg1)); 	// that we are trying to print might be too expensive to copy
    print(std::forward<Tn>(args)...);
  }

  // You also need to provide the default case, as usual with recursion
  void print() {}

  // Alternatively, by using folding you can implement the print function without recursion
  template <typename... Tn>
  void print_norec(Tn&&... args) { 	
	(handlePrint(std::forward<Tn>(args)),...);
  }
};

int main() {
  newPrint<int, char, std::string, bool>(5, 'a', "salsedine", true);

  printer p;
  p.print<int>(5, 4, 3, 2); 		 // You don't have to repeat the type for every parameter because of 
  p.print<char>('a', 'b', 'c', 'd'); // template argument deduction
  p.print<std::vector<int>>({2, 3, 4});
  p.print();
  p.print<int, char, std::string, bool>(5, 'a', "salsedine", true);
  p.print_norec<int, char, std::string, bool>(5, 'a', "salsedine", true);
}
