#include <iostream>

/* The nodiscard attribute is used on a function returning value to let
the compiler issue a warning when the function is called without doing nothing
on the returned value.*/
[[nodiscard("Try of nodiscard.")]] int func() { return 42; }

int main() {
    /* In this case the compiler will return an warning.*/
    func();
    return 0;
}