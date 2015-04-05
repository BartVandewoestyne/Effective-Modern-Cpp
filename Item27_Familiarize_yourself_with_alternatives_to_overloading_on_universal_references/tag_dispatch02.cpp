/*
 * Key idea:
 *
 *   Tag dispatching permits us to combine universal references and overloading.
 *
 */

#include <chrono>
#include <iostream>
#include <set>
#include <utility>
#include <type_traits>

std::multiset<std::string> names;    // global data structure

std::string nameFromIdx(int idx)   // as in Item 26
{
  return std::string("Bart");
}

void log(const std::chrono::system_clock::time_point& t, const char* s)
{
  std::cout << "Making log entry" << std::endl;
}

template<typename T>                             // non-integral
void logAndAddImpl(T&& name, std::false_type)    // argument:
{                                                // add it to
  auto now = std::chrono::system_clock::now();   // global data
  log(now, "logAndAdd");                         // structure
  names.emplace(std::forward<T>(name));
}

template<typename T>
void logAndAdd(T&& name)
{
  // This is not quite correct and will fail if T is an lvalue ref.
  //logAndAddImpl(std::forward<T>(name),
  //              std::is_integral<T>());  // not quite correct

  // This is correct, because we remove references.
  logAndAddImpl(
    std::forward<T>(name),
    std::is_integral<typename std::remove_reference<T>::type>()
  );

}

void logAndAddImpl(int idx, std::true_type)  // integral
{                                            // argument: look
  logAndAdd(nameFromIdx(idx));               // up name and
}                                            // call logAndAdd
                                             // with it
