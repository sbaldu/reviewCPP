// Here we learn about std::span, a new container introduced in c++20

#include <array>
#include <iostream>
#include <numeric>
#include <span>
#include <vector>

// Suppose that we define a function that prints the elements of a vector
template <typename T>
void print(const std::vector<T>& vec) {
  for (auto x : vec) {
	std::cout << x << '\n';
  }
}

// Good, but what if we want it for stl arrays?
// Let's overload it
template <typename T, std::size_t N>
void print(const std::array<T, N>& arr) {
  for (auto x : arr) {
	std::cout << x << '\n';
  }
}

// Ok ok, and if we want it for C style arrays?
// Then we need to overload again
template <typename T, std::size_t N>
void print(const T* arr) {
  for (size_t i{}; i < N; ++i) {
	std::cout << arr[i] << '\n';
  }
}

// Is there a better way? Yep! We can use std::span
// std::span contains a pointer to the first element of a sequential memory buffer, and its extent
// This means that a span can mimic any sequential data container
// We only need one overload for a function, taking in a span, and it will work for any sequential container
template <typename T, std::size_t N = std::dynamic_extent>
void print_span(const std::span<const T> seq) {
  for (const auto x : seq) {
	std::cout << x << '\n';
  }
}

int main() {
  std::vector<int> v(10);
  std::iota(v.begin(), v.end(), 1);
  print_span<int>(v);
  std::cout << "Works for std::vector!\n\n";

  std::array<int, 10> arr1;
  std::iota(arr1.begin(), arr1.end(), 1);
  print_span<int>(arr1);
  std::cout << "Works for std::array!\n\n";

  int arr2[] = {1,2,3,4,5,6,7,8,9,10};
  print_span<int>(arr2);
  std::cout << "Works for C style arrays!\n\n";
}
