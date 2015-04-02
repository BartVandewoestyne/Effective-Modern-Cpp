/*
 * Key Idea:
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container. In addition, dependent types
 *   must be preceded by typename.
 */

#include <list>
#include <memory>

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                      // MyAllocList<T>::type
struct MyAllocList {                      // is synonym for
  typedef std::list<T, MyAlloc<T>> type;  // std::list<T,
};                                        //   MyAlloc<T>>

template<typename T>
class Widget {                            // Widget<T> contains
private:                                  // a MyAllocList<T>
  typename MyAllocList<T>::type list;     // as a data member
  // ...
};
