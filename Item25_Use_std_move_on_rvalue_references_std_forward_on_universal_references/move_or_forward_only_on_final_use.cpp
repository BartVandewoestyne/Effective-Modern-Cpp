/*
 * Key idea:
 *
 *   Here, we want to make sure that text's value doesn't get changed by
 *   sign.setText, because we want to use that value when we call
 *   signHistory.add.  Ergo the use of std::forward on only the final use of the
 *   universal reference.
 */

// TODO:
//  fix sign and signHistory

#include <chrono>
#include <utility>

template<typename T>                       // text is
void setSignText(T&& text)                 // univ. reference
{
  sign.setText(text);                      // use text, but
                                           // don't modify it

  auto now =                               // get current time
    std::chrono::system_clock::now();

  signHistory.add(now,
                  std::forward<T>(text));  // conditionally cast
}                                          // text to rvalue
