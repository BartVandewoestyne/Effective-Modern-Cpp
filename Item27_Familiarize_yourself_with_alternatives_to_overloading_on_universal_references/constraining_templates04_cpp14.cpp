/*
 * Key idea:
 *
 *   TODO
 */

#include <string>
#include <type_traits>

std::string nameFromIdx(int idx)   // as in Item 26
{
  return std::string("Bart");
}

class Person {
public:
  template<                                 // as before
    typename T,
    typename = std::enable_if_t<
      !std::is_base_of<Person, std::decay_t<T>>::value
      &&
      !std::is_integral<std::remove_reference_t<T>>::value
    >
  >
  explicit Person(T&& n)
  : name(std::forward<T>(n))
  {
    // assert that a std::string can be created from a T object
    static_assert(
      std::is_constructible<std::string, T>::value,
      "Parameter n can't be used to construct a std::string"
    );

   // ...                   // the usual ctor work goes here
  }

  explicit Person(int idx)  // remainder of Person class (as before)
  : name(nameFromIdx(idx))
  { /* ... */ }

  // ...

private:
  std::string name;
};
