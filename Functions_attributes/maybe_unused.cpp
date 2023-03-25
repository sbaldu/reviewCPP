#include <iostream>

/* If the compiler warning level is set high enough, this function definition
might result in two compiler warnings if we don't use the two params. We can
suppres the warning relative to the use of the param2 my adding maybe_unused*/
int func(int param1, [[maybe_unused]] int param2) { return 42; }
