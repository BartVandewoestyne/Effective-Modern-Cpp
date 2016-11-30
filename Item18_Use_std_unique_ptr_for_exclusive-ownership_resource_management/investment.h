#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <iostream>

bool needStock = true;
bool needBond = false;
bool needRealEstate = false;

class Investment {
public:

                                // essential
  virtual ~Investment() {}      // design
                                // component
  
};

class Stock:
  public Investment { };

class Bond:
  public Investment { };

class RealEstate:
  public Investment { };

#endif  // INVESTMENT_H
