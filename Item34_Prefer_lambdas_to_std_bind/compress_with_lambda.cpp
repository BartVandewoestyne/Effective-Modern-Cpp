#include "compress.h"

auto compressRateL =                  // w is captured by
  [w](CompLevel lev)                  // value; lev is
  { return compress(w, lev); }        // passed by value

int main()
{
  compressRateL(CompLevel::High);     // arg is passed
                                      // by value
}
