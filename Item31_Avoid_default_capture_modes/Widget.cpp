#include "Widget.h"
#include "utils.h"

void Widget::addFilter() const
{
  // default by-value capture
  filters.emplace_back(
    [=](int value) { return value % divisor == 0; }
  );

  //filters.emplace_back(                             // error!
  //  [](int value) { return value % divisor == 0; }  // divisor
  //);                                                // not
  //                                                  // available

  //filters.emplace_back(
  //  [divisor](int value)              // error! no local
  //  { return value % divisor == 0; }  // divisor to capture
  //);

  /* version 1: compilers treat the version with a default by-value capture like
     this: */
  auto currentObjectPtr = this;

  filters.emplace_back(
    [currentObjectPtr](int value)
    { return value % currentObjectPtr->divisor == 0; }
  );
  /* version 1 end */


  /* version 2: make a local copy of the data member you want to capture */
  auto divisorCopy = divisor;             // copy data member

  // variant 1: capture the local copy
  filters.emplace_back(
    [divisorCopy](int value)              // capture the copy
    { return value % divisorCopy == 0; }  // use the copy
  );

  // variant 2: default by-value capture
  filters.emplace_back(
    [=](int value)                        // capture the copy
    { return value % divisorCopy == 0; }  // use the copy
  );

  // variant 3: use generalized lambda captures
  filters.emplace_back(               // C++14 only:
    [divisor = divisor](int value)    // copy divisor to closure
    { return value % divisor == 0; }  // use the copy
  );
  /* version 2 end */

}
