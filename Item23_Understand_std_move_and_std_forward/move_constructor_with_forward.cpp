/*
 * Key idea:
 *
 *   std::forward requires both a function argument (rhs.s) and a template type
 *   argument (std::string).
 */

#include <string>

class Widget {
public:
  Widget(Widget&& rhs)                     // unconventional,
  : s(std::forward<std::string>(rhs.s))    // undesirable
  { ++moveCtorCalls; }                     // implementation

private:
  static std::size_t moveCtorCalls;
  std::string s;
};
