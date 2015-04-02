/*
 * Key idea:
 *
 *   Example that shows how to use decltype to compute the return type.
 *   Needs refinement though!
 */

void authenticateUser() {}

template<typename Container, typename Index>  // works, but
auto authAndAccess(Container& c, Index i)     // requires
  -> decltype(c[i])                           // refinement
{
  authenticateUser();
  return c[i];
}
