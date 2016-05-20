/*
 * If conditionsAreSatisfied() returns true, all is well, but if it returns
 * false or throws an exception, the std::thread object t will be joinable when
 * its destructor is called at the end of doWork.  That would cause program
 * execution to be terminated.
 */

#include <functional>
#include <iostream>
#include <thread>
#include <vector>

#include "utils.h"

#if __cplusplus == 201103L
constexpr auto tenMillion = 10000000;         // see Item 15
                                              // for constexpr
#elif __cplusplus == 201402L
constexpr auto tenMillion = 10'000'000;       // C++14
#endif

bool doWork(std::function<bool(int)> filter,  // returns whether
            int maxVal = tenMillion)          // computation was
{                                             // performed; see
                                              // Item 2 for
                                              // std::function

  std::vector<int> goodVals;                  // values that
                                              // satisfy filter

  std::thread t([&filter, maxVal, &goodVals]  // populate
                {                             // goodVals
                  for (auto i = 0; i <= maxVal; ++i)
                   { if (filter(i)) goodVals.push_back(i); }
                });

  auto nh = t.native_handle();                // use t's native
  // ...                                      // handle to set
                                              // t's priority

  if (conditionsAreSatisfied()) {
    t.join();                                 // let t finish
    performComputation(goodVals);
    return true;                              // computation was
  }                                           // performed

  return false;                               // computation was
}                                             // not performed

int main()
{
    std::function<bool(int)> filter = someFilter;
    doWork(filter, 10);
}
