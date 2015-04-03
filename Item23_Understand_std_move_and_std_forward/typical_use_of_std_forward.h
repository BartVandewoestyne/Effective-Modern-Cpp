/*
 * Key idea:
 *
 *   - Whereas std::move unconditionally casts its argument to an rvalue,
 *     std::forward does it only under certain conditions.  std::forward is a
 *     conditional cast.
 */

#ifndef TYPICAL_USE_OF_STD_FORWARD_H
#define TYPICAL_USE_OF_STD_FORWARD_H

#include <chrono>
#include <utility>

class Widget {};

void makeLogEntry(const char* message,
                  const std::chrono::time_point<std::chrono::system_clock> t) {}

void process(Widget& lvalArg);            // process lvalues
void process(Widget&& rvalArg);           // process rvalues

template<typename T>                      // template that passes
void logAndProcess(T&& param)             // param to process
{
  auto now =
    std::chrono::system_clock::now();     // get current time

  makeLogEntry("Calling 'process'", now);
  process(std::forward<T>(param));
}

#endif /* TYPICAL_USE_OF_STD_FORWARD_H */
