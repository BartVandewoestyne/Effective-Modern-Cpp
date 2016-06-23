/*
 * Key ideas:
 *
 *   1. A function with an auto return type that returns a braced initializer list
 *      won't compile.
 *
 *   2. When auto is used in a parameter type specification in a C++14 lambda
 *      expression, things won't compile.
 */

#include <vector>

auto createInitList()
{
  //return {1, 2, 3};    // error: can't deduce type
  //                     // for {1, 2, 3}
}

int main()
{
  std::vector<int> v;

  auto resetV =
    [&v](const auto& newValue) { v = newValue; };  // C++14

  //resetV( {1, 2, 3} );  // error! can't deduce type
  //                      // for { 1, 2, 3 }
}
