/*
 * Key idea:
 *
 *   In many contexts, an array decays into a pointer to its first element.
 *
 */

int main()
{
    const char name[] = "J. P. Briggs";  // name's type is
                                         // const char[13]

    const char * ptrToName = name;       // array decays to pointer
}
