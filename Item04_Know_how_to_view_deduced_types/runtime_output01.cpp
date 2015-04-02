/*
 * Key idea:
 *
 *   Calls to std::type_info::name are not guaranteed to return anything
 *   sensible, but implementations try to be helpful.  The level of helpfullnes
 *   varies.
 */

#include <iostream>
#include <typeinfo>

const int theAnswer = 42;

auto x = theAnswer;
auto y = &theAnswer;

int main()
{
    std::cout << typeid(x).name() << '\n';   // display types for
    std::cout << typeid(y).name() << '\n';   // x and y
}
