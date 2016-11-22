/*
 * Key idea:
 *
 *   * Only if there's no way to convert the types of the arguments in a braced
 *     initializer to the type in a std::initializer_list do compilers fall back
 *     on normal overload resolution.
 */

#include <iostream>

class Widget {
public:

  Widget(int i, bool b) {  // as before
    std::cout << "Widget(int, bool)" << std::endl;
  };

  Widget(int i, double d) {  // as before
    std::cout << "Widget(int double)" << std::endl;
  };

  // std::init_list element type is now std::string
  Widget(std::initializer_list<std::string> il) {  // added
    std::cout << "Widget(std::initializer_list<std::string>)" << std::endl;
  };

  // ...    // no implicit 
            // conversion funcs

};

int main()
{
  {
    Widget w1(10, true);  // uses parens, still calls first ctor

    Widget w2{10, true};  // uses braces, now calls first ctor

    Widget w3(10, 5.0);   // uses parens, still calls second ctor

    Widget w4{10, 5.0};   // uses braces, now calls second ctor
  }
}
