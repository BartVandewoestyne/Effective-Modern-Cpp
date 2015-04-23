/*
 * Key ideas: TODO
 *
 * TODO: fix compile error
 */

#include "Widget.h"
#include "utils.h"

#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

int computeSomeValue1()
{
  return 1;
}

int computeSomeValue2()
{
  return 2;
}

int computeDivisor(int calc1, int calc2)
{
  return calc1 + calc2;
}

void addDivisorFilter()
{
  auto calc1 = computeSomeValue1();
  auto calc2 = computeSomeValue2();

  auto divisor = computeDivisor(calc1, calc2);

  filters.emplace_back(                              // danger!
    [&](int value) { return value % divisor == 0; }  // ref to
                                                     // divisor
  );                                                 // will
                                                     // dangle!

  filters.emplace_back(
    [&divisor](int value)             // danger! ref to
    { return value % divisor == 0; }  // divisor will
  );                                  // still dangle


  filters.emplace_back(                              // now
    [=](int value) { return value % divisor == 0; }  // divisor
  );                                                 // can't
                                                     // dangle
}

void addDivisorFilter2()
{
  static auto calc1 = computeSomeValue1();  // now static
  static auto calc2 = computeSomeValue2();  // now static

  static auto divisor =                     // now static
    computeDivisor(calc1, calc2);

  filters.emplace_back(
    [=](int value)                    // captures nothing!
    { return value % divisor == 0; }  // refers to above static
  );

  ++divisor;                          // modify divisor

}

template<typename C>
void workWithContainer(const C& container)
{
  auto calc1 = computeSomeValue1();             // as above
  auto calc2 = computeSomeValue2();             // as above

  auto divisor = computeDivisor(calc1, calc2);  // as above

  using ContElemT = typename C::value_type;     // type of
                                                // elements in
                                                // container

  using std::begin;                             // for
  using std::end;                               // genericity;
                                                // see Item 13

  // C++11 version
  if (std::all_of(                              // if all values
       begin(container), end(container),        // in container
       [&](const ContElemT& value)              // are multiple
       { return value % divisor == 0; })        // of divisor...
     ) {
    // ...                                      // they are...

  } else {
    // ...                                      // at least one
  }                                             // isn't...

  // C++14 version:
  if (std::all_of(begin(container), end(container),
                  [&](const auto& value)              // C++14
                  { return value % divisor == 0; }))
  { } else { }

}


void doSomeWork()
{
  auto pw =                      // create Widget; see
    std::make_unique<Widget>();  // Item 21 for
                                 // std::make_unique

  pw->addFilter();               // add filter that uses
                                 // Widget::divisor

}                                // destroy Widget; filters
                                 // now holds dangling pointer!

int main()
{
  filters.emplace_back(                       // see Item 42 for
    [](int value) { return value % 5 == 0; }  // info on
  );                                          // emplace_back

}
