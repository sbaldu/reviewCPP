#include <iostream>

namespace mycode{
    void foo(){
        std::cout<<"foo() called in my namespace"<<std::endl;
    }
}

using namespace mycode;
/*
Subsequent code can refer to cout without prepending the namespace, but other items in the std
namespace still need to be explicit
*/
using  std::cout;

int main(){

cout<<"Hi every one"<<std::endl;

foo();

}