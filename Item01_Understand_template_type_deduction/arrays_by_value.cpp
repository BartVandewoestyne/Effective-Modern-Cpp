/*
 * Key idea:
 *
 *   Because array parameter declarations are treated as if they were pointer
 *   parameters, the type of an array that's passed to a template function by
 *   value is deduced to be a pointer type.
 */

template<typename T>
void f(T param) {}  // template with by-value parameter

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    f(name);                   // what types are deduced for T and param?
                               // -> name is array, but T deduced as const char*
}
