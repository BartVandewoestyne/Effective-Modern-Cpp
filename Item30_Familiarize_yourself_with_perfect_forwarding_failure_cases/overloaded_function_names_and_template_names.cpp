/*
 * Key idea:
 *
 *   - Overloaded function names and template names are a perfect forwarding
 *     failure case.
 *
 *   - The way to get a perfect-forwarding function like fwd to accept an
 *     overloaded function name is to manually specify the overload or
 *     instantiation you want to have forwarded.
 */

#include <utility>

//void f(int (*pf)(int));   // pf = "processing function"
void f(int pf(int)) {}      // declares same f as above


int processVal(int value) { return 1; }
int processVal(int value, int priority) { return 1; }


template<typename T>
T workOnVal(T param)  // template for processing values
{
  T x;
  return x;
}


template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}


int main()
{
  f(processVal);        // fine

  //fwd(processVal);    // error! which processVal?


  //fwd(workOnVal);     // error! which workOnVal
                        // instantiation?


  using ProcessFuncType =                        // make typedef;
    int (*)(int);                                // see Item 9

  ProcessFuncType processValPtr = processVal;    // specify needed
                                                 // signature for
                                                 // processVal

  fwd(processValPtr);                            // fine

  fwd(static_cast<ProcessFuncType>(workOnVal));  // also fine
}
