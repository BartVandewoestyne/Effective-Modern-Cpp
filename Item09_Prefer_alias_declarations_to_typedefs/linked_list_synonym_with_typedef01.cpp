/*
 * Key Idea:
 *
 *   Typedefs cannot be templatized, and therefore need to be wrapped
 *   in a metafunction or container.
 */

#include <list>
#include <memory>

class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                      // MyAllocList<T>::type
struct MyAllocList {                      // is synonym for
  typedef std::list<T, MyAlloc<T>> type;  // std::list<T,
};                                        //   MyAlloc<T>>

MyAllocList<Widget>::type lw;             // client code
