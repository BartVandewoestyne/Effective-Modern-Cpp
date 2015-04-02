/*
 * Key idea:
 *
 *   Supporting such use means we need to revise the declaration for c to accept
 *   both lvalues and rvalues, and that means that c needs to be a universal
 *   reference.
 */

#include <string>
#include <deque>

#include "uref_cpp11.h"

std::deque<std::string> makeStringDeque()   // factory function
{
  std::deque<std::string> ds;
  return ds;
}

int main()
{
  
  // make copy of 5th element of deque returned
  // from makeStringDeque
  auto s = authAndAccess(makeStringDeque(), 5);
}
