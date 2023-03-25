#include<iostream>
#include<optional>

/* It stores a value or not.
It's used for parameters of a function to be optional or not.
You have to state the type of the optional parameter or return.*/

std::optional<int> getData(bool givenIt){
    if (givenIt){
        return 42;
    }
    return std::nullopt;
}

int main(){
    std::optional<int> data1 {getData(true)};
    std::optional<int> data2 {getData(false)};
    
    /* To determine whether an optional has a value, use the has_value() method. */
    std::cout << "data1.has_value: " << data1.has_value() << std::endl;
    /* On the terminal will appear one*/
    return 0;
}
