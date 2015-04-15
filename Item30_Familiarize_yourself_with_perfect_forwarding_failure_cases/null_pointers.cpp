/*
 * Key idea:
 *
 *   Neither 0 or NULL can be perfect-forwarded as a null pointer.  The fix is
 *   easy, however: pass nullptr instead of 0 or NULL
 */

#include <iostream>
#include <memory>
#include <utility>

class Widget {};

//void f(Widget *pw) {
//  std::cout << "f(Widget *)" << std::endl;
//}

void f(std::unique_ptr<Widget> pw) {
  std::cout << "f(std::unique_ptr<Widget>)" << std::endl;
}

template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}

template<typename... Ts>
void fwd(Ts&&... param)             // accept any arguments
{
  f(std::forward<Ts>(param)...);    // forward them to f
}

int main()
{
  f(0);        // fine, passes null pointer
  f(NULL);     // also fine, also passes null pointer
  f(nullptr);

  //fwd(0);      // error!
  //fwd(NULL);   // also error!
  fwd(nullptr);
}
