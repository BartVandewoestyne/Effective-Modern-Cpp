/*
 * Key Ideas:
 *
 *   - nullptr shines especially brightly when templates enter the picture.
 *
 *   - The following code for f1, f2, and f3 can be templatized.
 */

#include <iostream>
#include <memory>
#include <mutex>

class Widget {};

int    f1(std::shared_ptr<Widget> spw) { std::cout << "f1" << std::endl; }  // call these only when
double f2(std::unique_ptr<Widget> upw) { std::cout << "f2" << std::endl; }  // the appropriate
bool   f3(Widget* pw) { std::cout << "f3" << std::endl; }                   // mutex is locked

int main()
{

  std::mutex f1m, f2m, f3m;      // mutexes for f1, f2, and f3
  
  using MuxGuard =               // C++11 typedef; see Item 9
    std::lock_guard<std::mutex>;

  {
    MuxGuard g(f1m);             // lock mutex for f1
    auto result = f1(0);         // pass 0 as null ptr to f1
  }                              // unlock mutex

  // ...

  {
    MuxGuard g(f2m);             // lock mutex for f2
    auto result = f2(NULL);      // pass NULL as null ptr to f2
  }                              // unlock mutex

  // ...

  {
    MuxGuard g(f3m);             // lock mutex for f3
    auto result = f3(nullptr);   // pass nullptr as null ptr to f3
  }                              // unlock mutex

}
