#include <memory>
#include <vector>

class Widget {};

void makeLogentry(Widget *pw) {}

auto loggingDel = [](Widget *pw)        // custom deleter
                  {                     // (as in Item 19)
                    makeLogentry(pw);
                    delete pw;
                  };

std::unique_ptr<                       // deleter type is
  Widget, decltype(loggingDel)         // part of ptr type
  > upw(new Widget, loggingDel);

std::shared_ptr<Widget>                // deleter type is not
  spw(new Widget, loggingDel);         // part of ptr type

auto customDeleter1 = [](Widget *pw) { /* ... */ };  // custom deleters,
auto customDeleter2 = [](Widget *pw) { /* ... */ };  // each with a
                                                     // different type

std::shared_ptr<Widget> pw1(new Widget, customDeleter1);
std::shared_ptr<Widget> pw2(new Widget, customDeleter2);

std::vector<std::shared_ptr<Widget>> vpw { pw1, pw2 };


// BAD BAD BAD
auto pw = new Widget;

//std::shared_ptr<Widget> spw1(pw, loggingDel);  // create control
//                                               // block for *pw

//std::shared_ptr<Widget> spw2(pw, loggingDel);  // create 2nd
//                                               // control block
//                                               // for *pw!

std::shared_ptr<Widget> spw1(new Widget,       // direct use of new
                             loggingDel);

std::shared_ptr<Widget> spw2(spw1);            // spw2 uses same
                                               // control block as spw1
