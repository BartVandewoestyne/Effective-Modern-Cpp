/*
 * Key idea:
 *
 *   References to references are illegal in C++.
 */

int main()
{
    int x;

    //auto& & rx = x;    // error! can't declare reference to reference
}
