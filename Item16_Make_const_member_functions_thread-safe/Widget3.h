/*
 * Key idea:
 *
 *   For a single variable or memory location requiring synchronization, use of
 *   a std::atomic is adequate, but once you go to two or more variables or
 *   memory locations that require manipulation as a unit, you should reach for
 *   a mutex.
 */
#include <atomic>
#include <mutex>

int expensiveComputation1() { return 1; }
int expensiveComputation2() { return 2; }

class Widget {
public:

  int magicValue() const
  {
    std::lock_guard<std::mutex> guard(m);  // lock m

    if (cacheValid) return cachedValue;
    else {
      auto val1 = expensiveComputation1();
      auto val2 = expensiveComputation2();
      cachedValue = val1 + val2;
      cacheValid = true;
      return cachedValue;
    }
  }                                        // unlock m

private:
  mutable std::mutex m;
  mutable int cachedValue;                 // no longer atomic
  mutable bool cacheValid{ false };        // no longer atomic
};
