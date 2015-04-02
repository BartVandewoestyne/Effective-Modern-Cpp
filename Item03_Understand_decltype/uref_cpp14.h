/*
 * Key idea:
 *
 *   Supporting to pass rvalue containers to this function means we need to
 *   revise the declaration for c to accept both lvalues and rvalues, and that
 *   means that c needs to be a universal reference.
 */

#include <utility>

void authenticateUser() {}

template<typename Container, typename Index>            // final
decltype(auto)                                          // C++14
authAndAccess(Container&& c, Index i)                   // version 
{
  authenticateUser();
  return std::forward<Container>(c)[i];
}
