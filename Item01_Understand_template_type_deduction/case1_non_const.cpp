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
 *   then, in the simplest case when ParamType is a reference type or a pointer
 *   type, but not a universal reference, type deduction works like this:
 *
 *   1. If expr's type is a reference, ignore the reference part.
 *   2. Then pattern-match expr's type against ParamType to determine T.
 */

template<typename T>
void f(T& param) {}   // param is a reference

int main()
{
  int x = 27;         // x is an int
  const int cx = x;   // cx is a const int
  const int& rx = x;  // rx is a reference to x as a const int

  f(x);               // T is int, param's type is int&

  f(cx);              // T is const int,
                      // param's type is const int&

  f(rx);              // T is const int,
                      // param's type is const int&
}
