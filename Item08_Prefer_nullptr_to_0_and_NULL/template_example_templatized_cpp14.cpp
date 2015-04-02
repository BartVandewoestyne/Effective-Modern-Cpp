/*
 * Key Idea:
 *
 *   In C++14, the trailing return type is replaced
 *   with decltype(auto) as its return type.
 */

#include <iostream>
#include <memory>
#include <mutex>

using MuxGuard =            // C++11 typedef; see Item 9
  std::lock_guard<std::mutex>;


class Widget {};

int    f1(std::shared_ptr<Widget> sp) { std::cout << "f1" << std::endl; }  // call these only when
double f2(std::unique_ptr<Widget> up) { std::cout << "f2" << std::endl; }  // the appropriate
bool   f3(void* ptr) { std::cout << "f3" << std::endl; }                   // mutex is locked

template<typename FuncType,
         typename MuxType,
         typename PtrType>
decltype(auto) lockAndCall(FuncType func,     // C++14
                           MuxType& mutex,
                           PtrType ptr)
{
  MuxGuard g(mutex);
  return func(ptr);
}

int main()
{

  std::mutex f1m, f2m, f3m;   // mutexes for f1, f2, and f3
  
  //auto result1 = lockAndCall(f1, f1m, 0);        // error!

  //auto result2 = lockAndCall(f2, f2m, NULL);     // error!

  auto result3 = lockAndCall(f3, f3m, nullptr);  // fine

}
