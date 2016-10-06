/*
 * Key idea:
 *
 *   - The Point constructor can be declared constexpr, because if the arguments
 *   passed to it are known during compilation, the value of the data memberss
 *   of the constructed Point can also be known during compilation.  Points so
 *   initialized could thus be constexpr.
 *
 *   - The getters xValue and yValue can be constexpr, because if they're
 *   invoked on a Point object with a value known during compilation (e.g. a
 *   constexpr Point object), the values of the data members x and y can be
 *   known during compilation.  That makes it possible to write constexpr
 *   functions that call Point's getters and to initialize constexpr objects
 *   with the results of such functions.
 */

#include "Point_cpp11.h"

constexpr Point
midpoint(const Point& p1, const Point& p2) noexcept
{
  return { (p1.xValue() + p2.xValue()) / 2,    // call constexpr
           (p1.yValue() + p2.yValue()) / 2 };  // member funcs
}

int main()
{
  constexpr Point p1(9.4, 27.7);   // fine, "runs" constexpr
                                   // ctor during compilation

  constexpr Point p2(28.8, 5.3);   // also fine

  constexpr auto mid = midpoint(p1, p2);  // init constexpr
                                          // object w/result of
                                          // constexpr function
}
