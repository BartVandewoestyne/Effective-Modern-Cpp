/**
 * Key idea:
 *
 *   std::async's default launch policy is std::launch::async or-ed together with
 *   std::launch::deferred.
 */

#include <future>
#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}

int main()
{
    auto fut1 = std::async(f);                     // run f using
                                                   // default launch
                                                   // policy
    
    auto fut2 = std::async(std::launch::async |    // run f either
                           std::launch::deferred,  // async or
                           f);                     // deferred

    fut1.get();
    fut2.get();

    return 0;
}
