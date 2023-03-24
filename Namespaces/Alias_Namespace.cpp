#include <iostream>

/*
A namespace alias can be used to give a new and possibly shorter name to another
namespace.
*/

namespace MyLibraries::Subsection1::Subsection2 {
void foo() { std::cout << "foo() was called" << std::endl; }
}  // namespace MyLibraries::Subsection1::Subsection2

namespace Francesco = MyLibraries::Subsection1::Subsection2;

int main() { Francesco::foo(); }
