#include <iostream>
/*Can be marked in order to say that some code is deprecated and will return a
 * warning or a compilation error*/
[[deprecated("Unsafe method, please use xyz")]] void func();