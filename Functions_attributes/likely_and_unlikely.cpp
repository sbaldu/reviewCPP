#include <iostream>
/* This attributes can be used to help the compiler to optimize the code. Adding
likely to a if statement structure menas that we say to the compiler if that
peace of code is more likely to occur or not. */
int main() {
  int val{/**/};
  if (val > 10) [[unlikely]] {     /* */
  } else if (val < 5) [[likely]] { /* */
  } else {
    /**/
  }
}