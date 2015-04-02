/*
 * Key idea:
 *
 *   There is an additional incentive to apply noexcept to functions that won't
 *   produce exceptions: it permits compilers to generate better object code.
 */

#include <stdexcept>
#include <string>

int f(int x) throw();  // C++98 approach: f emits no
                       // exceptions

int f(int x) noexcept;  // C++11 approach: f emits no
                        // exceptions

int f(int x) noexcept    // C++98 version would use "throw()"
{
  if (x > 0) return x * x - 42;                  // if x > 0 ...

  throw std::invalid_argument(                   // else throw!
    "Invalid value for x: " + std::to_string(x)
  );
}
