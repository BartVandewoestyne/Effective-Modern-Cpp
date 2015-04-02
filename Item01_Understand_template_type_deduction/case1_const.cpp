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
 *   then, in the simplest case when ParamType is a pointer type or a reference
 *   type, but not a universal reference, type deduction works like this:
 *
 *   1. If expr's type is a reference, ignore the reference part.
 *   2. Then pattern-match expr's type against ParamType to determine T.
 *
 *   If the type of f's parameter is changed from T& to const T&, the constness
 *   of cx and rx continues to be respected, but because we're now assuming that
 *   param is a reference-to-const, there's no longer a need for const to be
 *   deduced as part of T.
 */

template<typename T>
void f(const T& param) {}  // param is now a ref-to-const

int main()
{
  int x = 27;              // as before
  const int cx = x;        // as before
  const int& rx = x;       // as before

  f(x);                    // T is int, param's type is const int&

  f(cx);                   // T is int, param's type is const int&

  f(rx);                   // T is int, param's type is const int&
}
