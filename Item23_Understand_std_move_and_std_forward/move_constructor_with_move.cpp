/*
 * Key idea:
 *
 *   - std::move's attractions are convenience, reduced likelihood of error, and
 *     greater clarity.
 *
 *   - std::move requires only a functino argument (rhs.s)
 */

#include <string>

class Widget {
public:
  Widget(Widget&& rhs)
  : s(std::move(rhs.s))
  { ++moveCtorCalls; }

private:
  static std::size_t moveCtorCalls;
  std::string s;
};
