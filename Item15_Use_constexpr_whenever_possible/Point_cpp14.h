/*
 * Key idea:
 *
 *   Two restrictions are lifted in C++14:
 *     - In C++11, constexpr member functions are implicitly const.
 *     - void isn't a literal type in C++11, so constexpr member functions must
 *       not return void.
 */

class Point {
public:
  constexpr Point(double xVal = 0, double yVal = 0) noexcept
  : x(xVal), y(yVal)
  {}

  constexpr double xValue() const noexcept { return x; }
  constexpr double yValue() const noexcept { return y; }

  constexpr void setX(double newX) noexcept  // C++14
  { x = newX; }

  constexpr void setY(double newY) noexcept  // C++14
  { y = newY; }

private:
  double x, y;
};
