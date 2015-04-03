/*
 * Key idea:
 *
 *   For a reference to be universal, type deduction is necessary, but it's not
 *   sufficient.  The form of the reference declaration must also be correct,
 *   and that form is quite constrained.
 */

#include <utility>
#include <vector>

class Widget {};


template<typename T>
void f(std::vector<T>&& param);  // param is an rvalue reference

template<typename T>
void f(const T&& param);         // param is an rvalue reference

template<typename MyTemplateType>       // param is a
void someFunc(MyTemplateType&& param);  // universal reference

int main()
{
    std::vector<int> v;
//    f(v);                        // error! can't bind lvalue to
                                 // rvalue reference
}
