/*
 * Key idea:
 *
 *   In C++14, the existence of function return type deduction (see Item 3)
 *   means that makeInvestment could be implemented in a simpler and more
 *   encapsulated fashion.
 */

#include "investment.h"
#include "utils.h"

#include <memory>

template<typename... Ts>
auto makeInvestment(Ts&&... args)                  // C++14
{

  auto delInvmt = [](Investment* pInvestment)   // this is now
                  {                             // inside
                    makeLogEntry(pInvestment);  // make-
                    delete pInvestment;         // Investment
                  };

  std::unique_ptr<Investment, decltype(delInvmt)>  // as
    pInv(nullptr, delInvmt);                       // before

  if ( needStock )            // as before
  {
    pInv.reset(new Stock(std::forward<Ts>(args)...));
  }
  else if ( needBond )         // as before
  {
    pInv.reset(new Bond(std::forward<Ts>(args)...));
  }
  else if ( needRealEstate )  // as before
  {
    pInv.reset(new RealEstate(std::forward<Ts>(args)...));
  }

  return pInv;                                             // as before
}

int main ()
{
  // ...

  auto pInvestment =                    // pInvestment is of type
    makeInvestment( /* arguments */ );  // std::unique_ptr<Investment>

  // ...

  std::shared_ptr<Investment> sp =      // converts std::unique_ptr
    makeInvestment( /* arguments */ );  // to std::shared_ptr

}                                       // destroy *pInvestment
