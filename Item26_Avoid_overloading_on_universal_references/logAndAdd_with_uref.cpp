/*
 * Key idea:
 *
 *   The inefficiencies in the second and third calls can be eliminated by
 *   rewriting logAndAdd to take a universal reference (see Item 24) and, in
 *   accord with Item 25, std::forwarding this reference to emplace.
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

template<typename T>
void logAndAdd(T&& name)
{
  auto now = std::chrono::system_clock::now();
  log(now, "logAndAdd");
  names.emplace(std::forward<T>(name));
}

int main()
{
  std::string petName("Darla");          // as before

  logAndAdd(petName);                    // as before, copy
                                         // lvalue into multiset

  logAndAdd(std::string("Persephone"));  // move rvalue instead
                                         // of copying it

  logAndAdd("Patty Dog");                // create std::string
                                         // in multiset instead of
                                         // copying a temporary
                                         // std::string
}
