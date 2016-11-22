/*
 * Key idea:
 *
 *   * If you create a std::vector of a numeric type (e.g., a std::vector<int>)
 *     and you pass two arguments to the constructor, whether you enclose those
 *     arguments in parentheses or braces makes a tremendous difference.
 */

#include <vector>

int main()
{
  std::vector<int> v1(10, 20);  // use non-std::initializer_list
                                // ctor: create 10-element
                                // std::vector, all elements have
                                // value of 20

  std::vector<int> v2{10, 20};  // use std::initializer_list ctor:
                                // create 2-element std::vector,
                                // element values are 10 and 20
}
