/*
 * Key idea:
 *
 *   If the function template looks like this:
 *
 *     template <typename T>
 *     void f(ParamType param);
 *
 *   then two types are deduced: one for T and one for ParamType.  These types
 *   are frequently different, because ParamType often contains adornments,
 *   e.g., const- or reference qualifiers.
 */

template<typename T>
void f(const T& param) {}  // ParamType is const T&

int main()
{
  int x = 0;
  f(x);                    // call f with an int
}
