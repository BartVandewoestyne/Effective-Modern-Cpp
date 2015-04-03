/*
 * Key Idea:
 *
 *   std::shared_ptr doesn't require pointed-to types to be
 *   complete, and hence no special member functions need to
 *   be declared here.
 */

#include <memory>

class Widget {                  // in "widget.h"
public:
  Widget();
                                // no declarations for dtor
                                // or move operations

private:
  struct Impl;
  std::shared_ptr<Impl> pImpl;  // std::shared_ptr
};                              // instead of std::unique_ptr
