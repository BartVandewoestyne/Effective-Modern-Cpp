/**
 * Key idea:
 *
 *   Using std::async with the default launch policy has some interesting implications.
 *
 * TODO: improve this example.
 */

#include <future>
#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}

int main()
{
    auto fut = std::async(f);  // run f using default launch policy
}
