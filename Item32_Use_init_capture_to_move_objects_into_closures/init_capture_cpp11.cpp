/**
 * Key idea:
 *
 *   Example showing how you can accomplish move capture in a language lacking
 *   support for move capture.
 *
 *   A lambda expression is simply a way to cause a class to be generated and an
 *   object of that type to be created.  There is nothing you can do with a
 *   lambda that you can't do by hand.
 */

#include <memory>

#include "Widget.h"

class IsValAndArch {                         // "is validated
public:                                      // and archived"
  using DataType = std::unique_ptr<Widget>;

  explicit IsValAndArch(DataType&& ptr)      // Item 25 explains
  : pw(std::move(ptr)) {}                    // use of std::move

  bool operator()() const
  { return pw->isValidated() && pw->isArchived(); }

private:
  DataType pw;
};

int main()
{
  // REMARK: due to the use of std::make_unique, this line is C++14 and not
  // C++11!!!
  auto func = IsValAndArch(std::make_unique<Widget>());
}
