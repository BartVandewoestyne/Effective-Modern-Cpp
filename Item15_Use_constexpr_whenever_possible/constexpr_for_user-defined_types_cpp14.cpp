#include "Point_cpp14.h"

constexpr Point
midpoint(const Point& p1, const Point& p2) noexcept
{
  return { (p1.xValue() + p2.xValue()) / 2,    // call constexpr
           (p1.yValue() + p2.yValue()) / 2 };  // member funcs
}

constexpr Point reflection(const Point& p) noexcept
{
  Point result;               // creat non-const Point

  result.setX(-p.xValue());   // set its x and y values
  result.setY(-p.yValue());

  return result;              // return copy of it
}

int main()
{
  constexpr Point p1(9.4, 27.7);   // as above
  constexpr Point p2(28.8, 5.3);   // also fine

  constexpr auto mid = midpoint(p1, p2);

  constexpr auto reflectedMid =     // reflectedMid's value is
    reflection(mid);                // (-19.1 -16.5) and known
                                    // during compilation
}
