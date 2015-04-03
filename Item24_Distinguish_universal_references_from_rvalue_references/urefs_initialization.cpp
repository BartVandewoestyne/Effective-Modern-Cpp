// TODO: use Boost::TypeIndex instead
//#include "printtype.h"

#include <utility>
#include <iostream>

class Widget {};


template<typename T>
void f(T&& param)     // param is a universal reference
{
    // TODO: use Boost::TypeIndex instead
    //std::cout << Printtype<decltype(param)>().name() << std::endl;
}


int main()
{
    Widget w;
    f(w);             // lvalue passed to f; param's type is
                      // Widget& (i.e., an lvalue reference)

    f(std::move(w));  // rvalue passed to f; param's type is
                      // Widget&& (i.e., an rvalue reference)
}
