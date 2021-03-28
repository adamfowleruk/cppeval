

#pragma once

#include <memory> // for std::shared_ptr

/// \brief Standard Object Orientated patterns prior to converting to Templated approach
namespace oo {

// START INTERFACE PATTERN

/// \brief Example non-instantiable Interface pattern using 2D shapes
///
/// Note Interfaces typically have behaviour but no data (in the simplest/most common case)
class Shape {
public:
  Shape() = default;
  virtual ~Shape() = default;

  virtual double height() const = 0;
  virtual double width() const = 0;
  virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
  Rectangle(double width,double height);
  ~Rectangle() = default;

  double height() const override;
  double width() const override;
  double area() const override;

private:
  double mWidth;
  double mHeight;
};

class Square : public Shape {
public:
  Square(double width);
  ~Square() = default;

  double height() const override;
  double width() const override;
  double area() const override;

private:
  double mWidth;
};

class Circle : public Shape {
public:
  Circle(double radius);
  ~Circle() = default;

  double height() const override;
  double width() const override;
  double area() const override;

private:
  double mRadius;
};

// Now define a class that uses these
class Renderer {
public:
  Renderer(double xLeft,double xRight,double yTop,double yBottom);
  ~Renderer() = default;

  void draw(std::shared_ptr<Shape> toDraw);

private:
  double mLeft;
  double mRight;
  double mTop;
  double mBottom;
};

// START ABSTRACT CLASS PATTERN

// TODO


// START ABSTRACT CONTAINER PATTERN

// TODO

}