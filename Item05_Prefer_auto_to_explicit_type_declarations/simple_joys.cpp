/*
 * Key idea:
 *
 *   * Not using auto leads to certain inconveniences.
 */

#include <functional>
#include <memory>

#include "Widget.h"

// Simple joy 1: whether x gets initialized to zero or not, depends on the
// context.
int x;

// Simple joy 2: the simple joy of declaring a local variable to be initialized
// with the value of an iterator.
template<typename It>   // algorithm to dwim ("do what I mean")
void dwim(It b, It e)   // for all elements in range from
{                       // b to e
  while (b != e) {
    typename std::iterator_traits<It>::value_type
      currValue = *b;
    // ...
  }
}

// Simple joy 3: the delight of declaring a local variable whose type is that
// of a closure.  But the type of a closure is known only to the compiler, hence
// can't be written out...


// Perhaps you're thinking that we don't really need auto to declare a variable
// that holds a closure, because we use a std::function object:
std::function<bool(const std::unique_ptr<Widget>&,
                   const std::unique_ptr<Widget>&)>
  derefUPLess = [](const std::unique_ptr<Widget>& p1,
                   const std::unique_ptr<Widget>& p2)
                  { return *p1 < *p2; };
