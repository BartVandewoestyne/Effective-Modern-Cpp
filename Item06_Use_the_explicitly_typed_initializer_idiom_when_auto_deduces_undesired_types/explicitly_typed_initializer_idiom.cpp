/*
 * Key idea:
 *
 *   The typed initializer idiom forces auto to deduce the type you want it to
 *   have.
 *
 * See also comments and discussions in [1-3].
 *
 * References:
 *
 *   [1] http://www.aristeia.com/BookErrata/emc++-errata.html
 *   [2] http://stackoverflow.com/questions/25607216/why-should-i-prefer-the-explicitly-typed-initializer-idiom-over-explicitly-giv
 *   [3] https://herbsutter.com/2013/08/12/gotw-94-solution-aaa-style-almost-always-auto/
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
