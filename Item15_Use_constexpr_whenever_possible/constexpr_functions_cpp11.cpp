/*
 * Key ideas:
 *
 *   - The constexpr in front of pow doesn't say that pow returns a const value,
 *   it says that if base and exp are compile-time constants, pow's result may
 *   be used as a compile-time constant.  If base and/or exp are not
 *   compile-time constants, pow's result will be computed at runtime.
 *
 *   - In C++11, constexpr functions may contain no more than a single
 *   executable statement: a return.
 */

#include <array>

int readFromDB(const char* s)
{
  return 1;
}

constexpr                                     // pow's a constexpr func
int pow(int base, int exp) noexcept           // that never throws
{
  return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

int main()
{
  // compile-time-compute the size of a std::array:
  constexpr auto numConds = 5;                // # of conditions
  std::array<int, pow(3, numConds)> results;  // results has
                                              // 3^{numConds}
                                              // elements

  // runtime context:
  auto base = readFromDB("base");             // get these values
  auto exp = readFromDB("exponent");          // at runtime

  auto baseToExp = pow(base, exp);            // call pow function
                                              // at runtime
}
