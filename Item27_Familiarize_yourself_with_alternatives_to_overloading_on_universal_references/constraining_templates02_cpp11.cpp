/*
 * Key idea:
 *
 *   TODO
 */

#include <type_traits>

class Person {
public:
  template<
    typename T,
    typename = typename std::enable_if<
                 !std::is_base_of<Person,
                                  typename std::decay<T>::type
                                 >::value
               >::type
  >
  explicit Person(T&& n);
  // ...
};
