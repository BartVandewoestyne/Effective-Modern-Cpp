/*
 * Key idea
 *
 *   TODO
 */

#include <vector>

class Widget {};

int main()
{
  std::vector<Widget> vw;
  
  // ...
  
  Widget w;
  
  // ...             // work with w

  vw.push_back(w);   // add w to vw

  // ...
}
