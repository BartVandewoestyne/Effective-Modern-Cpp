//TODO: finish this!

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

template<typename... Ts>          // return std::unique_ptr
std::unique_ptr<Investment>       // to an object created
  makeInvestment(Ts&&... args);   // from the given args

int main ()
{
  // ...

  auto pInvestment =                    // pInvestment is of type
    makeInvestment( /* arguments */ );  // std::unique_ptr<Investment>

  // ...

}                                       // destroy *pInvestment

auto delInvmt = [](Investment* pInvestment)   // custom 
                {                             // deleter
                  makeLogEntry(pInvestment);  // (a lambda
                  delete pInvestment;         // expression)
                };

template<typename... Ts>                         // revised
std::unique_ptr<Investment, decltype(delInvmt)>  // return type
makeInvestment(Ts&&... args)
{
  std::unique_ptr<Investment, decltype(delInvmt)>  // ptr to be
    pInv(nullptr, delInvmt);                       // returned

  if ( /* a Stock object should be created */ )
  {
    pInv.reset(new Stock(std::forward<Ts>(args)...));
  }
  else if ( /* a Bond object shold be created */ )
  {
    pInv.reset(new Bond(std::forward<Ts>(args)...));
  }
  else if ( /* a RealEstate object should be created */ )
  {
    pInv.reset(new RealEstate(std::forward<Ts>(args)...));
  }

  return pInv;
}
