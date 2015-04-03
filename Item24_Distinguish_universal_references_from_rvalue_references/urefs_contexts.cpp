/*
 * Key idea:
 *
 *   Universal references arise in two contexts.
 */

class Widget {};

Widget&& var1 = Widget();                    // rvalue reference


// Context 1: function template parameters.
template<typename T>
void f(T&& param);                           // param is a universal reference

// Context 2: auto declarations.
auto&& var2 = var1;                          // var2 is a universal reference
