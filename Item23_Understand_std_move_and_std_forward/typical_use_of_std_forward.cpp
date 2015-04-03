#include "typical_use_of_std_forward.h"

#include <iostream>

void process(Widget& lvalArg) {
  std::cout << "process(Widget&)" << std::endl;
}

void process(Widget&& rvalArg) {
  std::cout << "process(Widget&&)" << std::endl;
}

int main()
{
  Widget w;

  logAndProcess(w);                // call with lvalue
  logAndProcess(std::move(w));     // call with rvalue
}
