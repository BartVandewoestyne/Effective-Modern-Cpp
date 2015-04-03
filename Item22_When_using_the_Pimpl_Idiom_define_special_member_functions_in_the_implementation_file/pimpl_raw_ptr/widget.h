/*
 * Key Idea:
 *
 *   Applying the Pimpl Idiom in C++98 - replace
 *   all data members with a raw pointer to a struct.
 *   Clients of this code no longer need to recompile if
 *   the headers involved with the incomplete types change.
 */

class Widget {        // still in header "widget.h"
public:
  Widget();
  ~Widget();          // dtor is needed - see below

private:
  struct Impl;        // declare implementation struct
  Impl *pImpl;        // and pointer to it
};
