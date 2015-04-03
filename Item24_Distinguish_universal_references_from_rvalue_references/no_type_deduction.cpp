/*
 * Key idea:
 *
 *   If you see "T&&" without type deduction, you're looking at an rvalue
 *   reference.
 */

class Widget {};


void f(Widget&& param);    // no type deduction;
                           // param is an rvalue reference

Widget&& var1 = Widget();  // no type deduction;
                           // var1 is an rvalue reference
