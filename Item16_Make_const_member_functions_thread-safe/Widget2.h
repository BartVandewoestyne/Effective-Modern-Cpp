/*
 * Key idea:
 *
 *   Reversing the order of the assignments to cachedValue and CacheValid
 *   eliminates that problem, but the result is even worse.
 */
#include <atomic>

int expensiveComputation1() { return 1; }
int expensiveComputation2() { return 2; }

class Widget {
public:

  int magicValue() const
  {
    if (cacheValid) return cachedValue;
    else {
      auto val1 = expensiveComputation1();
      auto val2 = expensiveComputation2();

      cacheValid = true;                     // uh oh, part 1
      return cachedValue = val1 + val2;      // uh oh, part 2
    }
  }

private:
  mutable std::atomic<bool> cacheValid { false };
  mutable std::atomic<int> cachedValue;
};
