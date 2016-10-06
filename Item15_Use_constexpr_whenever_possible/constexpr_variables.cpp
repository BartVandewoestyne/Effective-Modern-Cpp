/*
 * Key ideas:
 *
 *   - integral values that are constant and known during compilation can be
 *   used in contexts where C++ requires an integral constant expression.  Such
 *   contexts include specification of array sizes, integral template arguments
 *   (including lengths of std::array objects), enumerator values, alignment
 *   specifiers, and more.  If you want to use a variable for these kind of
 *   things, you certainly want to declare it constexpr, because then compilers
 *   will ensure that it has compile-time value.
 *
 *   - const doesn't offer the same guarantee as constexpr, because const
 *   objects need not be initialized with values known during compilation.
 */

#include <array>

int main()
{
  int sz;                             // non constexpr variable

  //constexpr auto arraysize1 = sz;   // error! sz's value not
                                      // known at compilation

  //std::array<int, sz> data1;        // error! same problem

  constexpr auto arraySize2 = 10;     // fine, 10 is a
                                      // compile-time constant

  std::array<int, arraySize2> data2;  // fine, arraySize2
                                      // is constexpr



  const auto arraySize = sz;          // fine, arraySize is
                                      // const copy of sz

  //std::array<int, arraySize> data;  // error! arraySize's value
                                      // not known at compilation
}
