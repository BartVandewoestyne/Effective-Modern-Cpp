/*
 * Key idea:
 *
 *   It is natural to declare the roots() function const, because it does not
 *   modify the polynomial.
 */

#include <vector>

class Polynomial {
public:
  using RootsType =        // data structure holding values
    std::vector<double>;   // where polynomial evals to zero
                           // (see Item 9 for info on "using")

  RootsType roots() const;
};
