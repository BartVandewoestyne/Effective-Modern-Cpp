/*
 * Key idea:
 *
 *   The C++11 version is almost the same as its C++14 counterpart, except that
 *   you have to specify the return type yourself.
 */

#include <utility>

void authenticateUser() {}

template<typename Container, typename Index>            // final
auto                                                    // C++11
authAndAccess(Container&& c, Index i)                   // version 
-> decltype(std::forward<Container>(c)[i])
{
  authenticateUser();
  return std::forward<Container>(c)[i];
}
