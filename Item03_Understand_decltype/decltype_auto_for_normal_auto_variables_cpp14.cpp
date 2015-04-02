/*
 * Key idea:
 *
 *   The use of decltype(auto) is not limited to function return types.  It can
 *   also be convenient for declaring variables when you want to apply the
 *   decltype type deduction rules to the initializing expression.
 */

class Widget {};

Widget w;

const Widget& cw = w;

auto myWidget1 = cw;            // auto type deduction:
                                // myWidget1's type is Widget

decltype(auto) myWidget2 = cw;  // decltype type deduction:
                                // myWidget2's type is
                                //   const Widget&
