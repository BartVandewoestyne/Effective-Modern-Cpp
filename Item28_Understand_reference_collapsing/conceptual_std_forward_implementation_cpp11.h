/*
 * Key idea:
 *
 *   A conceptual (not Standards-conformant) implementation of std::forward
 *   could look like this.
 *
 * TODO: add this to CMakeLists.txt so that it gets checked somehow.
 */

#include <type_traits>
#include <utility>

using std::move;
using std::remove_reference;

template<typename T>                              // in
T&& forward(typename                              // namespace
              remove_reference<T>::type& param)   // std
{
  return static_cast<T&&>(param);
}
