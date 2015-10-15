#include <future>
#include <vector>

// this container *might* block in its dtor, because one or more
// contained futures could refer to a shared state for a non-
// deferred task launched via std::async
std::vector<std::future<void>> futs;   // see Item 39 for info
                                       // on std::future<void>

class Widget {                         // Widget objects *might*
public:                                // block in their dtors
  // ...

private:
  std::shared_future<double> fut;
};
