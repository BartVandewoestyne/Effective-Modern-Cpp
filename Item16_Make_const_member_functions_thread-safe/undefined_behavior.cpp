/*
 * Key idea:
 *
 *   Inside roots, one or both of these threads might try to modify the data
 *   members rootsAreValid and rootVals.  That means that this code could have
 *   different threads reading and writing the same memory without
 *   synchronization, and that's the definition of a data race.  This code has
 *   undefined behavior.
 */

#include <thread>

#include "Polynomial2.h"

Polynomial p;

void func1()
{
  /* Thread 1 */
  auto rootsOfP = p.roots();
}

void func2()
{
  /* Thread 2 */
  auto valsGivingZero = p.roots();
}

int main()
{
  std::thread t1(func1);
  std::thread t2(func2);
 
  t1.join();
  t2.join();
}
