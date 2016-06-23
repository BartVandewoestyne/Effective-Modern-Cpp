/*
 * Key idea:
 *
 *   Sometimes, one needs decltype type deduction rules in cases where types are
 *   inferred.  C++14 makes this possible through the decltype(auto) specifier:
 *   auto specifies that the type is to be deduced, and decltype says that
 *   decltype rules should be used during the deduction.
 */

void authenticateUser() {}

template<typename Container, typename Index>  // C++14 only;
decltype(auto)                                // works, but
authAndAccess(Container& c, Index i)          // still requires
{                                             // refinement
  authenticateUser();
  return c[i];
}
