#include <iostream>

/*
Enumerated types let you define your own sequences so that you can declare
variables with values in that sequence.
*/

enum class Pokemon { Water, Fire, Grass };

enum class Orders { Pizza = 10, Pasta = 8, Dessert = 6 };

int main() {
  Pokemon Charizard = Pokemon::Fire;

  // you can't output direclty output a value of an enum class
  std::cout << static_cast<int>(Charizard) << "\n";
  // The result of this operation will be 1.

  Orders pastaOrder = Orders::Pasta;
  std::cout << "The price of the pasta order is :" << static_cast<int>(pastaOrder) << "\n";
  // The output will be 8.
}