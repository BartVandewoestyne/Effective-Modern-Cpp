/*
 * Key idea:
 *
 *   If you're willing to live with a little platform-dependent code that's easy
 *   to implement and produces better results than those based on typeid, it's
 *   worth noting that many compilers support a language extension that yieldds
 *   a printable representation of the full signature for a function, including,
 *   for functions generated from templates, types for both template and
 *   function parameters.
 */

#include <iostream>
#include <typeinfo>
#include <vector>

class Widget {};

template<typename T>                // template function to
void f(const T& param)              // be called
{
#if defined(__GNUC__)                        // For GNU and
  std::cout << __PRETTY_FUNCTION__ << '\n';  // Clang
#elif defined(_MSC_VER)
  std::cout << __FUNCSIG__ << '\n';          // For Microsoft
#endif
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
