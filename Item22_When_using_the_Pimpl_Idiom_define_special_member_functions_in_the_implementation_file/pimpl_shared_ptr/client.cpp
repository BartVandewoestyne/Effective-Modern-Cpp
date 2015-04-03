#include "widget.h"

int main()
{

  Widget w1;
  
  auto w2(std::move(w1));  // move-construct w2
  
  w1 = std::move(w2);      // move-assign w1

}
