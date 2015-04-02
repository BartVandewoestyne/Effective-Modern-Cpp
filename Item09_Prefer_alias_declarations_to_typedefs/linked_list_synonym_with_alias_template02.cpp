/*
 * Key Idea:
 *
 *   With alias declaration, dependent types no longer require
 *   to be preceded by typename (as does the cumbersome "::type" suffix).
 */

#include <list>
#include <memory>

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;  // as before

template<typename T>
class Widget {
private:
  MyAllocList<T> list;                         // no "typename",
  // ...                                       // no "::type"
};
