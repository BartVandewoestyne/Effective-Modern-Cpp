/*
 * Key idea:
 *
 *   * In constructor calls, parentheses and braces have the same meaning as
 *     long as std::initializer_list parameters are not involved.
 */

#include <iostream>

class Widget {
public:
  Widget(int i, bool b) { std::cout << "Widget(int, bool)" << std::endl; };      // ctors not declaring
  Widget(int i, double d) { std::cout << "Widget(int, double)" << std::endl; };  // std::initializer_list params
};

int main()
{
  // In constructor calls, parentheses and braces have the same meaning as
  // long as std::initializer_list parameters are not involved:
  Widget w1(10, true);  // calls first ctor
  Widget w2{10, true};  // also calls first ctor
  Widget w3(10, 5.0);   // calls second ctor
  Widget w4{10, 5.0};   // also calls second ctor
}
