#include <iostream>
#include <vector>

// First you define a class template representing points in cartesian coordinates
template <typename T>
class cartesian {
private:
  T m_x;
  T m_y;

public:
  cartesian(T x, T y) : m_x{x}, m_y{y} {}
};

// Then you want to create a class template whose member is a vector that contains points
// This points can be expressed in any coordinate system, so the type of coordinate should be
// a template
template <typename T, template <typename E> typename point>
class vec {
private:
  std::vector<point<T>> m_vec_of_points{};

public:
  vec(std::vector<point<T>> vec) : m_vec_of_points{vec} {}
};

int main() {
  // Create a point in cartesian coordinates, whose data members are ints
  cartesian<int> p{5, 4};
  // Then you create a container of points expressed in cartesian coordinates
  vec<int, cartesian> cont{{p}};
}
