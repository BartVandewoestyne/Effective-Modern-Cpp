/*
 * Key idea:
 *
 *   * Empty braces mean no arguments, not an empty std::initializer_list.
 */

#include <iostream>
#include <vector>

class Widget {
public:

  Widget() {  // default ctor
    std::cout << "Widget()" << std::endl;
  };

  Widget(const Widget& rhs) { // copy ctor
    std::cout << "Wiget(const Widget&)" << std::endl;
  }

  Widget(Widget&& rhs) { // move ctor
    std::cout << "Widget(Widget&&)" << std::endl;
  }

  Widget(std::initializer_list<int> il) {  // std::init_list ctor
    std::cout << "Widget(std::initializer_list<int>" << std::endl;
  };

  operator int() const {  // convert to int
    std::cout << "operator int() const" << std::endl;
  }

};

int main()
{
  Widget w1;    // calls default ctor

  Widget w2{};  // also calls default ctor

  Widget w3();  // most vexing parse! declares a function!

  Widget w4({});  // calls std::init_list ctor
                  // with empty list

  Widget w5{{}};  // ditto

  auto w6{w5};  // calls copy ctor, not
                // std::list_init<int> ctor, even
                // though Widget converts to int

  auto w7{std::move(w5)};  // ditto, but for move ctor
                           // (Item 28 has info on std::move)

  std::vector<int> v1(10, 20);  // use non-std::initializer_list
                                // ctor: create 10-element
                                // std::vector, all elements have
                                // value of 20

  std::vector<int> v2{10, 20};  // use std::initializer_list ctor:
                                // create 2-element std::vector,
                                // element values are 10 and 20
}
