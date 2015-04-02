/*
 * Key idea:
 *
 *   There's nothing in the rules about the existence of a member function
 *   template preventing compilers from generating the special member functions.
 *
 *   In the below case, compilers will still generate copy and move operations
 *   for Widget (assuming the usual conditions governing their generation are
 *   fulfilled), even though these templates could be instantiated to produce
 *   the signatures for the copy constructor and copy assignment operator. (That
 *   would be the case when T is Widget.)
 */

class Widget {
public:
  // ...
  template<typename T>              // construct Widget
  Widget(const T& rhs);             // from anything

  template<typename T>              // assign Widget
  Widget& operator=(const T& rhs);  // from anything
  // ...
};
