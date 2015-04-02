/*
 * Key idea:
 *
 *   In C++11, const_iterators are both easy to get and easy to use.
 */

#include <algorithm>
#include <vector>

int main()
{

  std::vector<int> values;                            // as before

  auto it =                                           // use cbegin
    std::find(values.cbegin(), values.cend(), 1983);  // and cend
  values.insert(it, 1998);

}
