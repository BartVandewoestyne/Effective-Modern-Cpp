/*
 * Key ideas:
 *
 *   logAndAdd is overloaded here.  Resolution of calls to the two overloads
 *   does not always work as expected.  The overload taking a universal
 *   reference is invoked in the last call, and that is probably not what we
 *   wanted...
 *
 *   Functions taking universal references are the greediest functions in C++.
 *   They instantiate to create exact matches for almost any type of argument.
 *   (The few kinds of arguments where this isn't the case are described in
 *   Item 30.)  This is why combining overloading and universal references is
 *   almost always a bad idea: the universal reference overload vacuums up far
 *   more argument types than the developer doing the overloading generally
 *   expects.
 */

#include <chrono>
#include <iostream>
#include <set>
#include <string>

std::multiset<std::string> names;      // global data structure

void log(const std::chrono::system_clock::time_point& t, const char* s)
{
  std::cout << "Making log entry" << std::endl;
}

std::string nameFromIdx(int idx)     // return name
{                                      // corresponding to idx
    std::string s("Test");
    return s;
}

template<typename T>
void logAndAdd(T&& name)
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(std::forward<T>(name));
}

void logAndAdd(int idx)
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(nameFromIdx(idx));
}

int main()
{

  short nameIdx;

  std::string petName("Darla");          // as before

  logAndAdd(petName);                    // as before, these
  logAndAdd(std::string("Persephone"));  // calls all invoke
  logAndAdd("Patty Dog");                // the T&& overload

  logAndAdd(22);                         // calls int overload

  nameIdx = 1;                           // give nameIdx a value
  //logAndAdd(nameIdx);                  // error!
}
