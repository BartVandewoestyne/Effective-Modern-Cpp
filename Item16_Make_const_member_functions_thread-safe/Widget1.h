/*
 * In a class caching an expensive-to-compute int, you might try to use a pair
 * of std::atomic variables instead of a mutex.  Sometimes, this will work a lot
 * harder than it should.
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
      cachedValue = val1 + val2;             // uh oh, part 1
      cacheValid = true;                     // uh oh, part 2
      return cachedValue;
    }
  }

private:
  mutable std::atomic<bool> cacheValid{ false };
  mutable std::atomic<int> cachedValue;
};
