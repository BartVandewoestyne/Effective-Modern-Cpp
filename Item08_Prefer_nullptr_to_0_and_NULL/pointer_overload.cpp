/*
 * Key Idea:
 *
 *   In C++98, passing 0 or NULL to pointer and integral overloads never calls
 *   the pointer overload. nullptr always calls the pointer overload.
 */

#include <iostream>

// Three overloads of f
void f(int) { std::cout << "f(int)" << std::endl; }
void f(bool) { std::cout << "f(bool)" << std::endl; }
void f(void*) { std::cout << "f(void*)" << std::endl; }

int main()
{
  f(0);       // calls f(int) overload, not f(void*)

  //f(NULL);  // might not compile, but typically calls
              // f(int) overload.  Never calls f(void*)

  f(nullptr);  // calls f(void*) overload
}
