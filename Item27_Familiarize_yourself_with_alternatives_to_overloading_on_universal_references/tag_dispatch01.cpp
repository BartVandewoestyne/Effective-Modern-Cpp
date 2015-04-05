/*
 * Key idea:
 *
 *   TODO
 *
 */

#include <chrono>
#include <iostream>
#include <set>

std::multiset<std::string> names;  // global data structure

void log(const std::chrono::system_clock::time_point& t, const char* s)
{
  std::cout << "Making log entry" << std::endl;
}

template<typename T>                   // make log entry and add
void logAndAdd(T&& name)               // name to data structure
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(std::forward<T>(name));
}
