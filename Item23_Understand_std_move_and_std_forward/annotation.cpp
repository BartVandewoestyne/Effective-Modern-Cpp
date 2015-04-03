/*
 * Key ideas:
 *
 *   - text is not moved into value, it is copied.
 *   - two lessons learned:
 *       1) don't declare objects const if you want to be able to move from
 *          them.
 *       2) std::move not only doesn't actually move anything, it doesn't even
 *          guarantee that the object it's casting will be eligible to be moved.
 *
 */

#include <string>

class Annotation {
public:

  //explicit Annotation(std::string text);  // param to be copied,
  //                                        // so per Item 41,
  //                                        // pass by value

  explicit Annotation(const std::string text)
  : value(std::move(text))  // "move" text into value; this code
  { /* ... */ }             // doesn't do what it seems to!

private:
  std::string value;
};
