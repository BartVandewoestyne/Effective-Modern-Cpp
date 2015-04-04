/*
 * Key idea:
 *
 *   Given a function returning a local variable by value, it is not a good idea
 *   to turn the copy into a move in the return statement.
 *
 *   The "copying" version of makeWidget can avoid the need to copy the local
 *   variable w by constructing it in the memory alloted for the function's
 *   return value.  This is known as Return Value Optimization (RVO).
 *
 *   The moving version of makeWidget does just what its name says it does
 *   (assuming Widget offers a move constructor): it moves the contents of w
 *   into makeWidget's return value location.
 *
 *   Developers trying to help their compilers optimize by applying std::move to
 *   a local variable that's being returned are actually limiting the
 *   optimization options available to their compilers!
 *
 *   When the RVO is permitted, either copy elision takes place or std::move is
 *   implicitly applied to local objects being returned.
 */
class Widget {};

Widget makeWidget()
{
  Widget w;               // local variable

  // ...                  // configure w

  return w;               // "copy" w into return value

  //return std::move(w);  // move w into return value
}                         // (don't do this!)


Widget makeWidget(Widget w)  // by value parameter of same
{                            // type as function's return
  // ...
  
  return w;                  // treat w as rvalue
}
