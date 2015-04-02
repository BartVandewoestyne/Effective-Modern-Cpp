/*
 * Key idea:
 *
 *   As of C++11, the special member functions club has two more inductees: the
 *   move constructor and the move assignment operator.  Their signatures are
 *   given here.
 */

class Widget {
public:
  // ...
  Widget(Widget&& rhs);             // move constructor
  
  Widget& operator=(Widget&& rhs);  // move assignment operator
  // ...
};
