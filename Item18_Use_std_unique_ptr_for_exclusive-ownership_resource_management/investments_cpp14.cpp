//TODO: finish this!

/*
 * Key idea:
 *
 *   In C++14, the existence of function return type deduction (see Item 3)
 *   means that makeInvestment could be implemented in a simpler and more
 *   encapsulated fashion.
 */

#include <memory>

class Investment {
public:
  // ...                        // essential
  virtual ~Investment();        // design
  // ...                        // component
};

class Stock:
  public Investment { };

class Bond:
  public Investment { };

class RealEstate:
  public Investment { };

template<typename... Ts>
auto makeInvestment(Ts&&... args);

int main ()
{
  // ...

  auto pInvestment =                    // pInvestment is of type
    makeInvestment( /* arguments */ );  // std::unique_ptr<Investment>

  // ...

}                                       // destroy *pInvestment

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

  if ( /* a Stock object should be created */ )            // as before
  {
    pInv.reset(new Stock(std::forward<Ts>(args)...));
  }
  else if ( /* a Bond object shold be created */ )         // as before
  {
    pInv.reset(new Bond(std::forward<Ts>(args)...));
  }
  else if ( /* a RealEstate object should be created */ )  // as before
  {
    pInv.reset(new RealEstate(std::forward<Ts>(args)...));
  }

  return pInv;                                             // as before
}
