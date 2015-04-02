/*
 * Key idea:
 *
 *   The results of std::type_info::name are not reliable.
 *   Compiler diagnostics are a more dependable source of information about the
 *   results of type deduction.
 */

#include <iostream>
#include <typeinfo>
#include <vector>

class Widget {};

template<typename T>  // declaration only for TD;
class TD;             // TD = "Type Displayer"

template<typename T>                // template function to
void f(const T& param)              // be called
{
  using std::cout;
  cout << "T =     " << typeid(T).name() << '\n';     // show T
  cout << "param = " << typeid(param).name() << '\n'; // show
                                                      // param's
                                                      // type

//  TD<T> TType;                    // elicit errors containing
//  TD<decltype(param)> paramType;  // T's and param's types
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
