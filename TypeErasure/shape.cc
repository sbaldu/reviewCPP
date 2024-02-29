
#include <iostream>
#include <memory>

// We want to represent shapes: circles, rectangles, squares, etc.
// We could do it with inheritance, but if for some reason we wanted to expand
// the functionality of each shape deriving from the base class, we would need
// to derive one or more times each of the derived classes. This would become
// very messy very quickly.
//
// Instead we use type erasure.
class Shape {
private:
  // We define a base class that defines the concept of a shape.
  struct ShapeConcept {
    virtual ~ShapeConcept() = default;
    virtual void draw() const = 0;
    virtual std::unique_ptr<ShapeConcept> clone() const = 0;
  };

  // We then define a class template which models the actual shapes
  template <typename T>
  class ShapeModel : public ShapeConcept {
  private:
    T m_object;

  public:
    ShapeModel(const T& obj) : m_object{obj} {}
    void draw() const override {
      // we need to forward declare the draw function, otherwise it
      // will try to use a method instead of the free functions
      // subsequently defined.
      void draw(const T&);
      draw(m_object);
    }
	// we need the clone function because we can't copy a unique_ptr
    std::unique_ptr<ShapeConcept> clone() const override { return std::make_unique<ShapeModel>(*this); }
  };

  // The shape object is inserted into a unique pointer to the concept
  std::unique_ptr<ShapeConcept> m_shape;

public:
  Shape() = delete;
  template <typename T>
  Shape(const T& shape) : m_shape{new ShapeModel<T>(shape)} {}

  Shape(const Shape& other) : m_shape{other.m_shape->clone()} {}
  Shape& operator=(const Shape& other) {
    m_shape = other.m_shape->clone();
    return *this;
  }
  Shape(Shape&&) = default;
  Shape& operator=(Shape&&) = default;
  friend void draw(const Shape& shape) { shape.m_shape->draw(); }
};

class Circle {
private:
  float m_radius;

public:
  Circle(float radius) : m_radius{radius} {}
};

class Rectangle {
private:
  float m_width;
  float m_height;

public:
  Rectangle(float width, float height) : m_width{width}, m_height{height} {}
};

class Square {
private:
  float m_side;

public:
  Square(float side) : m_side{side} {}
};

void draw(const Circle&) { std::cout << "O\n"; }
void draw(const Rectangle&) { std::cout << "|||||\n"; }
void draw(const Square&) { std::cout << "|||\n"; }

int main() {
  Shape circle{Circle{1.f}};
  Shape rectangle{Rectangle{1.f, 2.f}};
  Shape square{Square{2.f}};

  draw(circle);
  draw(rectangle);
  draw(square);
}
