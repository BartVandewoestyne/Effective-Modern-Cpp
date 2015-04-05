/*
 * Key idea:
 *
 *   TODO
 */

#include <type_traits>
#include <utility>

class Person {
public:
  template<
    typename T,
    typename = typename std::enable_if<
                 !std::is_same<Person,
                               typename std::decay<T>::type
                              >::value
               >::type
  >
  explicit Person(T&& n);
};

class SpecialPerson: public Person {
public:
  SpecialPerson(const SpecialPerson& rhs)  // copy ctor; calls
    : Person(rhs)                          // base class
    { /* ... */ }                          // forwarding ctor!

  SpecialPerson(SpecialPerson&& rhs)       // move ctor; calls
    : Person(std::move(rhs))               // base class
    { /* ... */ }                          // forwarding ctor!
};
