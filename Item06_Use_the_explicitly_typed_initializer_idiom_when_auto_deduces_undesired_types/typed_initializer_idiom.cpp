/*
 * Key idea:
 *
 *   The typed initializer idiom forces auto to deduce the type you want it to
 *   have.
 */

#include <vector>

double calcEpsilon()  // return tolerance value
{
  return 1.0; 
}

int main()
{
  /* Example 1 */

  {
    float ep = calcEpsilon();  // implicitly convert
                               // double -> float
  }
  
  { // explicitly typed initializer idiom
    auto ep = static_cast<float>(calcEpsilon());
  }

  /* Example 2 */

  std::vector<int> c;
  double d = 0.5;

  { // this obscures the fact that d is converted to an int
    int index = d*c.size();
  }

  { // explicitly typed initializer idiom
    auto index = static_cast<int>(d*c.size());
  }
}
