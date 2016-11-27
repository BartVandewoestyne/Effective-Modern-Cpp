/*
 * Key idea
 *
 *  The need for reference-qualified member functions is not common, but it can arise.
 */
#include <utility>
#include <vector>

class Widget {
public:
  using DataType = std::vector<double>;  // see Item 9 for
                                         // info on "using"

  DataType& data() &             // for lvalue Widgets,
  { return values; }             // return lvalue

  DataType&& data() &&           // for rvalue Widgets,
  { return std::move(values); }  // return rvalue

private:
  DataType values;
};

Widget makeWidget()
{
  Widget w;
  return w;
}

int main()
{
  Widget w;

  auto vals1 = w.data();             // calls lvalue overload for
                                     // Widget::data, copy-
                                     // constructs vals1

  auto vals2 = makeWidget().data();  // calls rvalue overload for
                                     // Widget::data, move-
                                     // constructs vals2
}
