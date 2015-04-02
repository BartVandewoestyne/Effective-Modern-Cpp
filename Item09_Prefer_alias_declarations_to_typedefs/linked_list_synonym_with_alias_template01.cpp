/*
 * Key Idea:
 *
 *   Alias declarations may be templatized (typedefs cannot).
 */

#include <list>
#include <memory>

class Widget {};

template<typename T>
class MyAlloc : public std::allocator<T> {};

template<typename T>                           // MyAllocList<T>
using MyAllocList = std::list<T, MyAlloc<T>>;  // is synonym for
                                               // std::list<T,
                                               //   MyAlloc<T>>

MyAllocList<Widget> lw;                        // client code
