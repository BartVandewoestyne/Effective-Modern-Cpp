/**
 * Key idea:
 *
 *   C++14 example showing how you can create a local std::vector, put an
 *   appropriate set of values into it, and then move it into a closure.
 */

#include <utility>
#include <vector>

int main()
{
  std::vector<double> data;             // object to be moved
                                        // into closure
  
  // ...                                // populate data
  
  auto func = [data = std::move(data)]  // C++14 init capture
              { /* uses of data */ };
}
