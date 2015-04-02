// TODO: finish this!

auto delInvmt1 = [](Investment* pInvestment)   // custom
                 {                             // deleter
                   makeLogEntry(pInvestment);  // as
                   delete pInvestment;         // stateless
                 };                            // lambda

template<typename... Ts>                          // return type
std::unique_ptr<Investment, decltype(delInvmt1)>  // has size of
makeInvestment(Ts&&... args);                     // Investment*


void delInvmt2(Investment* pInvestment)           // custom
{                                                 // deleter
  makeLogEntry(pInvestment)                       // as function
  delete pInvestment;
}

template<typename... Ts>                   // return type is
std::unique_ptr<Investment,                // sizeof Investment*
                void (*)(Investment*)>     // plus at least size
makeInvestment(Ts&&... args);              // of function pointer!
