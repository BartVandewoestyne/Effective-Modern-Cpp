/*
 * Key idea:
 *
 *   * In constructor calls, parentheses and braces have the same meaning as
 *     long as std::initializer_list parameters are not involved.
 *
 *   * If one or more constructors declare a parameter of type std::initializer_list,
 *     calls using the braced initialization syntax strongly prefer the overloads
 *     taking std::initializer_lists.  Strongly.  If there's any way for compilers
 *     to construe a call using braced initializer to be to a constructor taking a
 *     std::initializer_list, compilers will employ that interpretation.
 *
 *   * Even what would normally be copy and move construction can be hijacked by
 *     std::initializer_list constructors.
 */

#include <iostream>

class Widget {
public:

  Widget(int i, bool b) {  // as before
    std::cout << "Widget(int, bool)" << std::endl;
  };

  Widget(int i, double d) {  // as before
    std::cout << "Widget(int, double)" << std::endl;
  };

  Widget(std::initializer_list<long double> il) {  // added
    std::cout << "Widget(std::initializer_list<long double>)" << std::endl;
  };

  operator float() const {  // convert to float
    std::cout << "operator float() const" << std::endl;
  }

};

int main()
{
  {
    Widget w1(10, true);  // uses parens and, as before,
                          // calls first ctor

    Widget w2{10, true};  // uses braces, but now calls
                          // std::init_list ctor
                          // (10 and true convert to long double)

    Widget w3(10, 5.0);   // uses parens and, as before,
                          // calls second ctor

    Widget w4{10, 5.0};   // uses braces, but now calls
                          // std::initializer_list ctor
                          // (10 and 5.0 convert to long double)

    Widget w5(w4);        // uses parens, calls copy ctor

    Widget w6{w4};        // uses braces, calls
                          // std::initializer_list ctor
                          // (w4 converts to float, and float
                          // converts to long double)

    Widget w7(std::move(w4));  // uses parens, calls move ctor

    Widget w8{std::move(w4)};  // uses braces, calls
                               // std::initializer_list ctor
                               // (for same reason as w6)
  }
}
