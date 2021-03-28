
#pragma once

namespace templated {

class Rectangle {
public:
  Rectangle(double width,double height);
  ~Rectangle() = default;

  double height() const;
  double width() const;
  double area() const;

private:
  double mWidth;
  double mHeight;
};

class Square {
public:
  Square(double width);
  ~Square() = default;

  double height() const;
  double width() const;
  double area() const;

private:
  double mWidth;
};

class Circle {
public:
  Circle(double radius);
  ~Circle() = default;

  double height() const;
  double width() const;
  double area() const;

private:
  double mRadius;
};


class Renderer {
public:
  Renderer(double xLeft,double xRight,double yTop,double yBottom)
    : mLeft(xLeft), mRight(xRight), mTop(yTop), mBottom(yBottom)
  {
    ;
  }
  ~Renderer() = default;

  /// \brief Template draw function. 
  ///
  /// Three instances of this will be generated for our sample programme. 
  /// They are actually likely to be inlined within the main function, causing no extra code to be generated.
  template <typename ShapeT>
  void draw(const ShapeT& toDraw) {
    std::cout << "I've just drawn a shape from (" << mLeft << "," << mTop << ") to (" << (mLeft + toDraw.width()) << "," << (mTop + toDraw.height()) << ")" << std::endl;
  }

private:
  double mLeft;
  double mRight;
  double mTop;
  double mBottom;
};

}