                               Things to Remember
                               ------------------

* Braced initialization is the most widely usable initialization syntax, it
  prevents narrowing conversions, and it's immune to C++'s most vexing parse.

* During constructor overload resolution, braced initializers are matched to
  std::initializer_list parameters if at all possible, even if other
  constructors offer seemingly better matches.

* An example of where the choice between parentheses and braces can make a
  significant difference is creating a std::vector<numeric type> with two
  arguments.

* Choosing between parentheses and braces for object creation inside templates
  can be challenging.
