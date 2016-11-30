#include "investment.h"
#include "utils.h"

#include <memory>

auto delInvmt = [](Investment* pInvestment)   // custom 
                {                             // deleter
                  makeLogEntry(pInvestment);  // (a lambda
                  delete pInvestment;         // expression)
                };

// Variant 1
//template<typename... Ts>          // return std::unique_ptr
//std::unique_ptr<Investment>       // to an object created
//  makeInvestment(Ts&&... args);   // from the given args

// Variant 2
template<typename... Ts>                         // revised
std::unique_ptr<Investment, decltype(delInvmt)>  // return type
makeInvestment(Ts&&... args)
{
  std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
    pInv(nullptr, delInvmt);                       // returned

  if ( needStock )
  {
    pInv.reset(new Stock(std::forward<Ts>(args)...));
  }
  else if ( needBond )
  {
    pInv.reset(new Bond(std::forward<Ts>(args)...));
  }
  else if ( needRealEstate )
  {
    pInv.reset(new RealEstate(std::forward<Ts>(args)...));
  }

  return pInv;
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
