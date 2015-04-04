/*
 * Key ideas:
 *
 *   rvalue references bind only to objects that are candidates for moving.  If
 *   you have an rvalue reference parameter, you know that the object it's bound
 *   to may be moved.
 *
 *   rvalue references should be unconditionally cast to rvalues (via std::move)
 *   when forwarding them to other functions, because they're always bound to
 *   rvalues.
 */

#include <memory>
#include <string>

class SomeDataStructure {};

class Widget {
public:
    Widget(Widget&& rhs)               // rhs is rvalue reference
    : name(std::move(rhs.name)),
      p(std::move(rhs.p))
      { /* ... */ }

private:
    std::string name;
    std::shared_ptr<SomeDataStructure> p;
};
