#include <iostream>

namespace MyLibraries::Subsection1::Subsection2 {
void foo() { std::cout << "foo() was called" << std::endl; }
}  // namespace MyLibraries::Subsection1::Subsection2
// This upper code is equivalent to the following and older one

namespace MyLibraries {
namespace Subsection1 {
namespace Subsection2 {
void foo2() { std::cout << "foo2() was called" << std::endl; }
}  // namespace Subsection2
}  // namespace Subsection1
}  // namespace MyLibraries

