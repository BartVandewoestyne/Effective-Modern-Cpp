/*
 * Key Idea:
 *
 *   An alternative to overloading on universal references is to replace pass by
 *   reference with pass by value. This adheres to the guidance in Item 41 to
 *   consider passing objects by value when you know you'll copy them..
 */

#include <string>
#include <utility>

std::string nameFromIdx(int idx) {
  return std::string("Bart");
}

class Person {
public:
  explicit Person(std::string n)  // replaces T&& ctor; see
  : name(std::move(n)) {}         // Item 41 for use of std::move

  explicit Person(int idx)        // as before
  : name(nameFromIdx(idx)) {}

  // ...

private:
  std::string name;
};
