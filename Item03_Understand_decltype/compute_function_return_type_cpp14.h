/*
 * Key idea:
 *
 *   In C++14 we can omit the trailing return type, leaving just the leading
 *   auto.  With that form of declaration, auto does mean that type deduction
 *   will take place.  In particular, it means that compilers will deduce the
 *   function's return type from the function's implementation.
 */

template<typename Container, typename Index>  // C++14 only, and
auto authAndAccess(Container& c, Index i)     // not quite
                                              // correct
{
  authenticateUser();
  return c[i];              // return type deduced from c[i]
}
