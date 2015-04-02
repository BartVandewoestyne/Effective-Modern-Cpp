/*
 * Key idea:
 *
 *   If we're dealing with pass-by-value
 *
 *     template <typename T>
 *     void f(T param);        // param is now passed by value
 *
 *   That means that param will be a copy of whatever is passed in - a
 *   completely new object.  The fact that param will be a new object motivates
 *   the rules that govern how T is deduced from expr:
 *
 *   1. As before, if expr's type is a reference, ignore the reference part.
 *
 *   2. If, after ignoring expr's reference-ness, expr is const, ignore that,
 *      too.  If it's volatile, also ignore that. (volatile objects are uncommon.
 *      They're generally used only for implementing device drivers.)
 */

template<typename T>
void f(T param) {}          // param is now passed by value

int main()
{
  int x = 27;               // as before
  const int cx = x;         // as before
  const int& rx = x;        // as before
  f(x);                     // T's and param's types are both int

  f(cx);                    // T's and param's types are again both int

  f(rx);                    // T's and param's types are still both int


  const char* const ptr =   // ptr is const pointer to const object
    "Fun with pointers";

  f(ptr);                   // pass arg of type const char * const
}
