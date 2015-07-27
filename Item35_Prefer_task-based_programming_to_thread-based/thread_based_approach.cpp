/**
 * Key ideas:
 *
 *   - The task-based approach is typically superior to its thread-based counterpart.
 *
 *   - With the thread-based invocation, there's no straightforward way to get access
 *     to the return value of doAsyncWork.
 *
 *   - With the thread-based approach, if doAsyncWork throws, the program dies (via a call
 *     to std::terminate).
 */

#include <iostream>
#include <thread>

int doAsyncWork()
{
    std::cout << "doAsyncWork()" << std::endl;

    //throw;

    return 1;

}


int main()
{
    std::thread t(doAsyncWork);

    t.join();

    return 0;
}
