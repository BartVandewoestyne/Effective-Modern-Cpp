/*
 * Key Idea:
 *
 *   Scoped enums are strongly typed, and no implicit
 *   conversions are done. 
 */

#include <cstddef>
#include <vector>

enum class Color { black, white, red };  // enum is now scoped

std::vector<std::size_t>           // func. returning
primeFactors(std::size_t x) {      // prime factors of x
  std::vector<std::size_t> temp;
  return temp;
}

int main()
{
  Color c = Color::red;   // as before, but
                          // with scope qualifier

//  if (c < 14.5) {         // error! can't compare
//                          // Color and double
//    auto factors =        // error! can't pass Color to
//      primeFactors(c);    // function expecting std::size_t
//    // ...
//  }
}
