/*
 * Key idea:
 *
 *   It seems reasonable to assume that if you see "T&&" in source code, you're
 *   looking at an rvalue reference.  However, it's not quite that simple.
 */

#include <vector>

class Widget {};


void f(Widget&& param);          // rvalue reference

Widget&& var1 = Widget();        // rvalue reference

auto&& var2 = var1;              // not rvalue reference

template<typename T>
void f(std::vector<T>&& param);  // rvalue reference

template<typename T>
void f(T&& param);               // not rvalue reference
