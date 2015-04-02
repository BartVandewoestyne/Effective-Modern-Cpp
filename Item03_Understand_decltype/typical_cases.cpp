/*
 * Key idea:
 *
 *   decltype almost always parrots back the type of the name or expression you
 *   give it without any modification.
 */

#include <cstddef>
#include <iostream>

class Widget {};

const int i = 0;           // decltype(i) is const int

bool f(const Widget& w);   // decltype(w) is const Widget&
                           // decltype(f) is bool(const Widget&)

struct Point {
  int x, y;                // decltype(Point::x) is int
};                         // decltype(Point::y) is int

Widget w;                  // decltype(w) is Widget


template<typename T>       // simplified version of std::vector
class vector {
public:
  // ...
  T& operator[](std::size_t index);
  // ...
};

int main()
{

  if (f(w)) {}              // decltype(f(w)) is bool

  vector<int> v;            // decltype(v) is vector<int>
  // ...
  if (v[0] == 0) {}         // decltype(v[0]) is int&

}
