/*
Namespaces address the problem of naming conflicts between different pieces of
code. For example, you might be writing some code that has a function called
foo()
*/

#include <iostream>

namespace mycode {
void foo() { std::cout << "foo() called in my namespace" << std::endl; }
}  // namespace mycode

int main() { mycode::foo(); }