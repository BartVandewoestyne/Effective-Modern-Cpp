/*
 * Key idea:
 *
 *   Forwarding functions are, by their nature, generic. The fwd template, for
 *   example, accepts any type of argument, and forwards whatever it gets.  A
 *   logical extension of this genericity is for forwarding functions to be not
 *   just templates, but variadic templates, thus accepting any number of
 *   arguments.
 *
 */

#include <utility>

template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}

template<typename... Ts>
void fwd(Ts&&... param)             // accept any arguments
{
  f(std::forward<Ts>(param)...);    // forward them to f
}
