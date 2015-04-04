/*
 * Key idea:
 *
 *   This code is not unreasonable, but not as efficient as it could be.
 *
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

void logAndAdd(const std::string& name)
{
  auto now =                           // get current time
    std::chrono::system_clock::now();

  log(now, "logAndAdd");               // make log entry

  names.emplace(name);                 // add name to global data
}                                      // structure; see Item 42
                                       // for info on emplace

int main()
{
  std::string petName("Darla");

  logAndAdd(petName);                    // pass lvalue std::string

  logAndAdd(std::string("Persephone"));  // pass rvalue std::string

  logAndAdd("Patty Dog");                // pass string literal
}
