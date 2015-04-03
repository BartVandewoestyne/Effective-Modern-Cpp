                               Things to Remember
                               ------------------

* auto type deduction is usually the same as template type deduction, but auto
  type deduction assumes that a braced initializer represents a
  std::initializer_list, and template type deduction doesn't.

* auto in a function return type or a lambda parameter implies template type
  deduction, not auto type deduction.
