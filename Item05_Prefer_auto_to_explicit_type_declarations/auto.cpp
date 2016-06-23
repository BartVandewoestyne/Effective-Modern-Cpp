/*
 * Key idea:
 *
 *   * Some advantages of using auto are:
 *       - avoidance of uninitialized variables
 *       - less verbose variable declarations
 *       - the ability to directly hold closures
 *       - the ability to avoid problems related to "type shortcuts"
 */

#include <memory>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>

#include "Widget.h"

// auto variables have their type deduced from their initializer, so they must
// be initialized;

int x1;       // potentially uninitialized
//auto x2;    // error! initializer required
auto x3 = 0;  // fine, x's value is well-defined

// Declaring a local variable whose value is that of a dereferenced iterator:

template<typename It>    // as before
void dwim(It b, It e)
{
  while (b != e) {
    auto currValue = *b;
    // ...
  }
}

// Because auto uses type deduction, it can represent types known only to
// compilers:

auto derefUPLess =                       // comparison func.
  [](const std::unique_ptr<Widget>& p1,  // for Widgets
     const std::unique_ptr<Widget>& p2)  // pointed to by
  { return *p1 < *p2; };                 // std::unique_ptr

// In C++14, parameters to lambda expressions may involve auto:

auto derefLess =                         // C++14 comparison
  [](const auto& p1,                     // function for
     const auto& p2)                     // values pointed
  { return *p1 < *p2; };                 // to by anything
                                         // pointer-like

// Problems related to "type shortcuts":
std::vector<int> v;
//unsigned sz = v.size();
auto sz = v.size();      // sz's type is std::vector<int>::size_type

std::unordered_map<std::string, int> m;

int main()
{
  for (const std::pair<std::string, int>& p : m)  // Don't do this!
  {
    // do something with p
  }
  
  for (const auto& p : m)                         // Do this: more efficient and
  {                                               // easier to type!
    // do something with p
  }
}
