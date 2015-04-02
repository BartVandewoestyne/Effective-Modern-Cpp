/**
 *  Key ideas:
 *
 *    * Initialization values may be specified in many different ways.
 *
 *    * C++11 introduces 'uniform initialization' to address the confusion of
 *      multiple initialization syntaxes, as well as the fact that they don't
 *      cover all initialization scenarios.
 *
 *    * A feature of braced initialization is that it prohibits implicit
 *      narrowing conversions among built-in types.
 */
#include <atomic>
#include <vector>

class Widget {
public:
  Widget() {};
  Widget(int x) {};

  Widget(int i, bool b) {};    // ctors not declaring
  Widget(int i, double d) {};  // std::initializer_list params

// Default initialization values for non-static data members.
private:
  int x{0};   // fine, x's default value is 0
  int y = 0;  // also fine
  //int z(0);   // error!

};

int main()
{

  {
    int x(0);     // initializer is in parentheses
    int y = 0;    // initializer follows "="
    int z {0};    // initializer is in braces
  }

  {
    int z = {0};  // initializer uses "=" and braces
  }

  {
    Widget w1;       // call default constructor
    Widget w2 = w1;  // not an assignment; calls copy ctor
    w1 = w2;         // an assignment; calls copy operator=
  }

  // Braced initialization
  {
    std::vector<int> v{1, 3, 5};  // v's initial content is 1, 3, 5
  }

  // Uncopyable objects (e.g. std::atomics) may be initialized
  // using braces or parentheses, but not using "=":
  {
    std::atomic<int> ai1{0};   // fine
    std::atomic<int> ai2(0);   // fine
    //std::atomic<int> ai3 = 0;  // error!
  }

  // Implicit narrowing conversions:
  double x, y, z;
  //int sum1{x + y + z};  // error! sum of doubles may
                          // not be expressible as int

  // Initialization using parentheses and "=" doesn't check
  // for narrowing conversions, because that would break too
  // much legacy code:
  {
    int sum2 = x + y + z;    // okay (value of expression
                             // truncated to an int)
    int sum3(x + y + z);     // ditto
  }


  {
    Widget w1(10);  // call Widget ctor with argument 10
    //Widget w2();   // most vexing parse! declares a function
                     // named w2 that returns a Widget!

    void f(const Widget& w = Widget());  // w's default value is a
                                         // default-constructed
                                         // Widget
  }


  {
    Widget w3{};       // calls Widget ctor with no args
  }
  {
    void f(const Widget& w = Widget{});  // as before, w's default
                                         // value is a default-
                                         // constructed Widget
  }


  {
    auto v1 = -1;    // -1's type is int, and so is v1's
    auto v2(-1);     // -1's type is int, and so is v2's
    auto v3{-1};     // -1's type is still int, but
                     // v3's type is std::initializer_list<int>
    auto v4 = {-1};  // -1's type remains int, but
                     // v4's type is std::initializer_list<int>
  }

  // In constructor calls, parentheses and braces have the same meaning as
  // long as std::initializer_list parameters are not involved:
  {
    Widget w1(10, true);  // calls first ctor
    Widget w2{10, true};  // also calls first ctor
    Widget w3(10, 5.0);   // calls second ctor
    Widget w4{10, 5.0};   // also calls second ctor
  }

}
