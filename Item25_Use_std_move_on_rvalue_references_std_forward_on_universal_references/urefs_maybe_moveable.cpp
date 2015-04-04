/*
 * Key ideas:
 *
 *   A universal reference, might be bound to an object that's eligible for
 *   moving.  Universal references should be cast to rvalues only if they were
 *   initialized with rvalues.
 *
 *   Universal references should be conditionally cast to rvalues (via
 *   std::forward) when forwarding them, because they're only sometimes bound to
 *   rvalues.
 */

#include <memory>
#include <string>

class Widget {
public:
  template<typename T>
  void setName(T&& newName)             // newName is
  { name = std::forward<T>(newName); }  // universal reference

private:
  std::string name;
};
