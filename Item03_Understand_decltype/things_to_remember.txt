                               Things to Remember
                               ------------------

* decltype almost always yields the type of a variable or expression without any
  modifications.

* For lvalue expressions of type T other than names, decltype always reports a
  type of T&.

* C++14 supports decltype(auto), which, like auto, deduces a type from its
  initializer, but it performs the type deduction using the decltype rules.
