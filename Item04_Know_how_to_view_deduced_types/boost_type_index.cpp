/*
 * Key idea:
 *
 *   It is possible to produce accurate type information using Boost.TypeIndex.
 *
 */
#include <iostream>
#include <typeinfo>
#include <vector>

#include <boost/type_index.hpp>

class Widget {};

template<typename T>
void f(const T& param)
{
  using std::cout;
  using boost::typeindex::type_id_with_cvr;

  // show T
  cout << "T =     "
       << type_id_with_cvr<T>().pretty_name()
       << '\n';

  // show param's type
  cout << "param = "
       << type_id_with_cvr<decltype(param)>().pretty_name()
       << '\n';
}

std::vector<Widget> createVec()    // factory function
{
    std::vector<Widget> vw;
    Widget w;
    vw.push_back(w);
    return vw;
}

int main()
{

    const auto vw = createVec();        // init vw w/factory return

    if (!vw.empty()) {
      f(&vw[0]);                        // call f
      // ...
    }
}
