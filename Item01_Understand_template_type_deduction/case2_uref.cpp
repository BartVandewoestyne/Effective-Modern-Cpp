/*
 * Key idea:
 *
 *   Considering the general form for templates and calls to it:
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *     f(expr);                // deduce T and ParamType from expr
 *
 *   then, in the case when ParamType is a universal reference
 *   type, type deduction works like this:
 *
 *   * If expr is an lvalue, both T and ParamType are deduced to be lvalue
 *     references
 *   * If expr is an rvalue, the usual type deduction rules apply.
 *
 */

template<typename T>
void f(T&& param) {}      // param is now a universal reference

int main()
{
  int x = 27;             // as before
  const int cx = x;       // as before
  const int& rx = x;      // as before

  f(x);                   // x is lvalue, so T is int&,
                          // param's type is also int&

  f(cx);                  // cx is lvalue, so T is const int&,
                          // param's type is also const int&

  f(rx);                  // rx is lvalue, so T is const int&,
                          // param's type is also const int&

  f(27);                  // 27 is rvalue, so T is int,
                          // param's type is therefore int&&
}
