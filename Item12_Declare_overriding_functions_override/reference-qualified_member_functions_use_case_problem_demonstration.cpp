/*
 * Key idea:
 *
 *   The need for reference-qualified member functions is not common, but it can
 *   arise.
 */
#include <vector>

class Widget {
public:
  using DataType = std::vector<double>;  // see Item 9 for
                                         // info on "using"
  DataType& data() { return values; }

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

  auto vals1 = w.data();  // copy w.values into vals1

  auto vals2 = makeWidget().data();  // copy values inside the
                                     // Widget into vals2
}
