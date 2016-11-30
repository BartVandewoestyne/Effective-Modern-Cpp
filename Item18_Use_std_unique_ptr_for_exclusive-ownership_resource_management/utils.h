#ifndef UTILS_H
#define UTILS_H

#include <iostream>

class Investment;

void makeLogEntry(Investment* pInvestment)
{
    std::cout << "makeLogEntry()" << std::endl;
}

#endif  // UTILS_H
