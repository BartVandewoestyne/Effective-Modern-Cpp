/*
 * Key idea:
 *
 *   C++11 deprecates the automatic generation of copy operations for classes
 *   declaring copy operations or a destructor.  This means that if you have
 *   code that depends on the generation of copy operations in classes declaring
 *   a destructor or one of the copy operations, you should consider upgrading
 *   these classes to eliminate the dependence.  C++11's "=default" lets you say
 *   that explicitly.
 */

class Widget {
public:
  // ...
  ~Widget();                             // user-declared dtor

  // ...                                 // default copy-ctor
  Widget(const Widget&) = default;       // behavior is OK
  
  Widget&                                // default copy-assign
    operator=(const Widget&) = default;  // behavior is OK
  // ...
};
