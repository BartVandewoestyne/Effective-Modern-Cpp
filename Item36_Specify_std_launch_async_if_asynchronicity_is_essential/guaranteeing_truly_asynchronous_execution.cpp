/**
 * Key idea:
 *
 *   The way to guarantee that std::async will schedule the task for truly
 *   asynchronous execution is to pass std::launch::async as the first argument
 *   when you make the call to std::async.
 */

#include <future>
#include <iostream>

void f()
{
    std::cout << "f()" << std::endl;
}


int main()
{
    auto fut = std::async(std::launch::async, f);  // launch f
                                                   // asynchronously

    fut.get();

    return 0;
}
