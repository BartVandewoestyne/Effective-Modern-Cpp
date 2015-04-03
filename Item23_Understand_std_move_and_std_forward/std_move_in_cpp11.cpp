/*
 * Key idea:
 *
 *   In essence, std::move casts its argument to an rvalue, and that's all it
 *   does.
 */

#include <type_traits>
using std::remove_reference;

template<typename T>                       // in namespace std
typename remove_reference<T>::type&&
move(T&& param)
{
  using ReturnType =                       // alias declaration;
    typename remove_reference<T>::type&&;  // see Item 9

  return static_cast<ReturnType>(param);
}
