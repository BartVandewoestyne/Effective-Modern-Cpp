/*
 * Key Idea:
 *
 *   Unscoped enums implicitly convert to integral types,
 *   allowing the below to run. Scoped enums are strongly
 *   typed.
 */

#include <cstddef>
#include <vector>

enum Color { black, white, red };  // unscoped enum

std::vector<std::size_t>           // func. returning
primeFactors(std::size_t x) {      // prime factors of x
  std::vector<std::size_t> temp;
  return temp;
}

int main()
{
  Color c = red;
  // ...
  if (c < 14.5) {         // compare Color to double (!)

    auto factors =        // compute prime factors
      primeFactors(c);    // of a color (!)
    // ...
  }
}
