#include "ThreadRAII.h"
#include "utils.h"

#if __cplusplus == 201103L
constexpr auto tenMillion = 10000000;         // see Item 15
                                              // for constexpr
#elif __cplusplus == 201402L
constexpr auto tenMillion = 10'000'000;       // C++14
#endif

bool doWork(std::function<bool(int)> filter,  // as before
            int maxVal = tenMillion)
{
  std::vector<int> goodVals;                  // as before

  ThreadRAII t(
    std::thread([&filter, maxVal, &goodVals]
                {
                  for (auto i = 0; i <= maxVal; ++i)
                   { if (filter(i)) goodVals.push_back(i); }
                }),
                ThreadRAII::DtorAction::join  // RAII action
  );

  auto nh = t.get().native_handle();
  // ...

  if (conditionsAreSatisfied()) {
    t.get().join();
    performComputation(goodVals);
    return true;
  }

  return false;
}

int main()
{
    std::function<bool(int)> filter = someFilter;
    doWork(filter, 10);
}
