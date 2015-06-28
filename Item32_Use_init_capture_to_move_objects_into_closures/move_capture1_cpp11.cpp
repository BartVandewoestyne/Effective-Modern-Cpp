/**
 * Key idea:
 *
 *   C++11 example showing how you can emulate move capture in C++11 by
 *
 *   1. moving the object to be captured into a function object produced by
 *      std::bind and
 *   2. giving the lambda a reference to the "captured" object.
 */

#include <functional>
#include <utility>
#include <vector>

int main()
{
  std::vector<double> data;                    // object to be moved
                                               // into closure
  
  // ...                                       // populate data
  
  {
    auto func =
      std::bind(                               // C++11 emulation
        [](const std::vector<double>& data)    // of init capture
        { /* uses of data */ },
        std::move(data)
      );
  }

  {
    auto func =
      std::bind(                               // C++11 emulation
        [](std::vector<double>& data) mutable  // of init capture
        { /* uses of data */ },                // for mutable lambda
        std::move(data)
      );
  }
}
