/*
 * Key idea:
 *
 *   Although functions can't declare parameters that are truly arrays, they can
 *   declare parameters that are references to arrays.
 *
 *   The type deduced for T is the actual type of the array!  That type includes
 *   the size of the array, so in this example T is deduced to be const
 *   char[13], and the type of f's parameter (a reference to this array) is
 *   const char (&)[13].
 *
 */

template<typename T>
void f(T& param) {}  // template with by-reference parameter

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    f(name);                   // pass array to f
}
