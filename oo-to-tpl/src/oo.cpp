
#include "oo.h"
/* C++20 only
#include <numbers> // for pi_v
*/
// For  C++<20 :-
#define M_PI 3.1415927
#include <iostream> // for std::cout;

namespace oo {

Rectangle::Rectangle(double width,double height)
  : Shape(),
    mWidth(width),
    mHeight(height)
{
  ;
}

double
Rectangle::height() const {
  return mHeight;
}

double
Rectangle::width() const {
  return mWidth;
}

double
Rectangle::area() const {
  return mWidth * mHeight;
}



Square::Square(double width) 
  : Shape(),
    mWidth(width)
{
  ;
}

double
Square::height() const {
  return mWidth;
}

double
Square::width() const {
  return mWidth;
}

double
Square::area() const {
  return mWidth * mWidth;
}



Circle::Circle(double radius)
  : Shape(),
    mRadius(radius)
{
  ;
}

double
Circle::height() const {
  return 2 * mRadius;
}

double
Circle::width() const {
  return 2 * mRadius;
}

double
Circle::area() const {
  // C++20 only: return 2 * std::numbers::pi * mRadius;
  return 2 * M_PI * mRadius;
}



Renderer::Renderer(double xLeft,double xRight,double yTop,double yBottom)
  : mLeft(xLeft), mRight(xRight), mTop(yTop), mBottom(yBottom)
{
  ;
}

void
Renderer::draw(std::shared_ptr<Shape> toDraw) {
  std::cout << "I've just drawn a shape from (" << mLeft << "," << mTop << ") to (" << (mLeft + toDraw->width()) << "," << (mTop + toDraw->height()) << ")" << std::endl;
}

}