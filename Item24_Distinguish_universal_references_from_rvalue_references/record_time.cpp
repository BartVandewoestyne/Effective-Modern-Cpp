/*
 * Key idea:
 *
 *   auto universal references crop up quite a lot in C++14, because C++14
 *   lambda expressions may declare auto&& parameters.
 */

#include <utility>

auto timeFuncInvocation =
  [](auto&& func, auto&&... params)               // C++14
  {
    // start timer;
    std::forward<decltype(func)>(func)(           // invoke func
      std::forward<decltype(params)>(params)...   // on params
      );
    // stop timer and record elapsed time;
  };
