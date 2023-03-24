#include <iostream>

/*
Use always enum class, not enum.
Enum is an older version and can cause conflicts with code that was previously
defined. For example the following code will return an error.
*/

int main() {
    bool ok{false};
    enum Status { error, ok };
    /*
This code does not compile because the name ok is first defined to be a Boolean
variable, and later the same name is used as the name of an enumeration value.
    */
}