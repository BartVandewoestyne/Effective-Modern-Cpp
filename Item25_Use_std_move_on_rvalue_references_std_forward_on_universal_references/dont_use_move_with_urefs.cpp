/*
 * Key idea:
 *
 *   Using std::move with universal references is a bad idea, because that can
 *   have the effect of unexpectedly modifying lvalues (e.g., local variables).
 */

#include <iostream>
#include <string>

std::string getWidgetName()       // factory function
{
    return std::string("SomeWidgetName");
}

class Widget {

public:
  template<typename T>
  void setName(T&& newName)       // universal reference
  { name = std::move(newName); }  // compiles, but is
                                  // bad, bad, bad!

private:
  std::string name;
  //std::shared_ptr<SomeDataStructure> p;  // REMARK: this is not really necessary for this example.
};

int main()
{
    Widget w;

    auto n = getWidgetName();         // n is local variable

    w.setName(n);                     // moves n into w!

    std::cout << n << std::endl;      // n's value now unknown
}
