/*
 * Key idea:
 *
 *   Deducing types for auto is the same as deducing types for templates (with
 *   only one curious exception).
 */

template<typename T>                 // conceptual template for
void func_for_x(T param) {}          // deducing x's type

template<typename T>                 // conceptual template for
void func_for_cx(const T param) {}   // deducing cx's type

template<typename T>                 // conceptual template for
void func_for_rx(const T& param) {}  // deducing rx's type
                                  
void someFunc(int, double) {}  // someFunc is a function;
                               // type is void(int, double)

int main()
{
  auto x = 27;                // case 3 (x is neither ptr nor reference)
  
  const auto cx = x;          // case 3 (cx isn't either)

  const auto& rx = x;         // case 1 (rx is a non-universal ref.)

  auto&& uref1 = x;           // x is int and lvalue,
                              // so uref1's type is int&

  auto&& uref2 = cx;          // cx is const int and lvalue
                              // so uref2's type is const int&

  auto&& uref3 = 27;          // 27 is int and rvalue,
                              // so uref3's type is int&&


  func_for_x(27);             // conceptual call: param's
                              // deduced type is x's type

  func_for_cx(x);             // conceptual call: param's
                              // deduced type is cx's type

  func_for_rx(x);             // conceptual call: param's
                              // deduced type is rx's type

  const char name[] =         // name's type is const char[13]
    "R. N. Briggs";

  auto arr1 = name;           // arr1's type is const char*

  auto& arr2 = name;          // arr2's type is
                              // const char (&)[13]

  auto func1 = someFunc;      // func1's type is
                              // void (*)(int, double)

  auto& func2 = someFunc;     // func2's type is
                              // void (&)(int, double)

}
