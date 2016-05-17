/*
 * Key idea:
 *
 *   About the only situation in which C++11's support for const_iterators comes
 *   up a bit short is when you want to write maximally generic library code.
 *
 *   This works fine in C++14, but, sadly, not in C++11.
 *
 * TODO: C++14
 */

#include <algorithm>
#include <vector>

template<typename C, typename V>
void findAndInsert(C& container,         // in container, find
                   const V& targetVal,   // first occurrence
                   const V& insertVal)   // of targetVal, then
{                                        // insert insertVal
//  using std::cbegin;                     // there
//  using std::cend;

//  auto it = std::find(cbegin(container),  // non-member cbegin
//                      cend(container),    // non-member cend
//                      targetVal);

  // Support of `std::cbegin()`in C++14
  // url: http://stackoverflow.com/a/31038315
  using std::begin;                     // there
  using std::end;

  auto it = std::find(begin(container),  // non-member cbegin
                      end(container),    // non-member cend
                      targetVal);

  container.insert(it, insertVal);
}

int main()
{

  std::vector<int> values;                            // as before

  findAndInsert(values, 1983, 1998);

}
