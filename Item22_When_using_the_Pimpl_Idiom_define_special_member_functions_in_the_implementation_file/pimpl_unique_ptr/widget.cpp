/*
 * Key Idea:
 *
 *   Implementation of the Pimpl Idiom in C++11 -
 *   replaces the raw pointer with a smart pointer.
 *
 *   Note that this compiles, but will fail for clients
 *   because the destructor is not implemented.
 */

#include "widget.h"                // in "widget.cpp"
#include "gadget.h"
#include <memory>
#include <string>
#include <vector>

struct Widget::Impl {              // as before, definition of
  std::string name;                // Widget::Impl
  std::vector<double> data;
  Gadget g1, g2, g3;
};

Widget::Widget()                   // per Item 22 create
: pImpl(std::make_unique<Impl>())  // std::unique_ptr
{}                                 // via std::make_unique

//Widget::~Widget()                // ~Widget definition
//{}

Widget::~Widget() = default;        // same effect as above 

Widget::Widget(Widget&& rhs) = default;             // defini-
Widget& Widget::operator=(Widget&& rhs) = default;  // tions

Widget::Widget(const Widget& rhs)                   // copy ctor
: pImpl(std::make_unique<Impl>(*rhs.pImpl))
{}

Widget& Widget::operator=(const Widget& rhs)        // copy operator=
{
  *pImpl = *rhs.pImpl;
  return *this;
}
