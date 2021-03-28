
#include "tpl.h"
/* C++20 only
#include <numbers> // for pi_v
*/
// For  C++<20 :-
#define M_PI 3.1415927

namespace templated {

Rectangle::Rectangle(double width,double height)
  : mWidth(width),
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
  : mWidth(width)
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
  : mRadius(radius)
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



}