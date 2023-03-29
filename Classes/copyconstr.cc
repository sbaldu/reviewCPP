#include <iostream>
#include <vector>

// We create a simple class template that represents a grid
// So the elements are stored in a one-dimensional vector and we save the number of rows and cols of the grid
template <typename T>
class grid{
private:
  std::vector<T> m_vec;
  int m_rows;
  int m_cols;
public:
  // We define the constructor and the getters
  grid(int rows = 0, int cols = 0) 
	: m_rows{rows}, m_cols{cols} { m_vec = {1, 6, 8}; }
  int rows() const { return m_rows; }
  int cols() const { return m_cols; }
  std::vector<T> vec() const { return m_vec; }
};

int main() {
  // We construct an object and print it's content
  grid<int> s(4,5);
  std::cout << s.rows() << ' ' << s.cols() << '\n';
  for(auto x : s.vec()) { std::cout << x << '\n'; }
  // Then we define another grid and initialize it by passing the first one
  // Note that this works even if we didn't manually write the copy constuctor
  grid<int> t(s);
  std::cout << t.rows() << ' ' << t.cols() << '\n';
  // Furthermore, if we print the content we see that it's identical to that of the first grid
  for(auto x : t.vec()) { std::cout << x << '\n'; }

  // If we don't write the copy constructor and copy assignment operator, the compiler writes
  // them for us, and in most cases his are good enough. This is the idea behind the rule 
  // of zero, that says that you shouldn't write the special constructor unless you really need to, 
  // and just let the compiler take care of it
}
