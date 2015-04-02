/*
 * Key idea:
 *
 *   In some situations, a mutex is overkill.  For example, if all you're doing
 *   is counting how many times a member function is called, a std::atomic
 *   counter will often be a less expensive way to go.
 */
#include <atomic>
#include <cmath>

class Point {                          // 2D point
public:

  double distanceFromOrigin() const noexcept  // see Item 14
  {                                           // for noexcept

    ++callCount;                       // atomic increment

    return std::sqrt((x*x)+(y*y));
  }

private:
  mutable std::atomic<unsigned> callCount{ 0 };
  double x, y;
};
