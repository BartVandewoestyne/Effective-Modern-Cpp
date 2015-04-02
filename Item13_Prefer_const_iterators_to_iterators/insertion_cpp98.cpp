/*
 * Key idea:
 *
 *   const_iterators were so much trouble in C++98.
 */

#include <algorithm>
#include <vector>

int main()
{

  std::vector<int> values;

  // Approach 1: using iterators in C++98

  std::vector<int>::iterator it =
    std::find(values.begin(), values.end(), 1983);
  values.insert(it, 1998);


  // Approach 2: using const_iterators in C++98

  typedef std::vector<int>::iterator IterT;             // type-
  typedef std::vector<int>::const_iterator ConstIterT;  // defs

  ConstIterT ci =
    std::find(static_cast<ConstIterT>(values.begin()),  // cast
              static_cast<ConstIterT>(values.end()),    // cast
              1983);
  //values.insert(static_cast<IterT>(ci), 1998);  // may not
                                                  // compile; see
                                                  // below
}
