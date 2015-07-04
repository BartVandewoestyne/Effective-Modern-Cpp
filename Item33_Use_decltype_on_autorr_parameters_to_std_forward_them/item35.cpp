/**
 * Key idea:
 *
 *   Use decltype on auto&& parameters to std::forward them.
 */

#include <utility>

int normalize(int x) { return x; }
int func(int x) { return x; }

int main()
{
  {
    // If normalize treats lvalues differently from rvalues, this lambda isn't
    // really written properly, because it always passes an lvalue (the
    // parameter x) to normalize, even if the argument that was passed to the
    // lambda was an rvalue.
    auto f = [](auto x){ return func(normalize(x)); };
  }
  
  {
    auto f =
       [](auto&& param)
       { return func(normalize(std::forward<decltype(param)>(param))); };
  }
  
  {
    // C++14 lambdas can also be variadic.
    auto f =
       [](auto&&... params)
       { return func(normalize(std::forward<decltype(params)>(params)...)); };
  }
}
