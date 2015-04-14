/*
 * Key idea:
 *
 *   A common use case for std::forward looks like this.
 *
 * TODO: add this to CMakeLists.txt somehow.
 */

void someFunc(int x) {}

template<typename T>
void f(T&& fParam)
{
  // ...                              // do some work

  someFunc(std::forward<T>(fParam));  // forward fParam to
}                                     // someFunc
