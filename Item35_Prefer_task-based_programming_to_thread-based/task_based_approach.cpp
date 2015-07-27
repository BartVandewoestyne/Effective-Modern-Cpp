/**
 * Key ideas:
 *
 *   - The task-based approach is typically superior to its thread-based counterpart.
 *
 *   - With the task-based approach, it is easy to get access to the return value of doAsyncWork,
 *     because the future returned from std::async offers the get function.
 *
 *   - The get function also provides access to the exception if doAsyncWork throws an exception.
 */
#include <future>
#include <iostream>

int doAsyncWork()
{
    std::cout << "doAsyncWork()" << std::endl;

    //throw;

    return 1;
}


int main()
{
    auto fut = std::async(doAsyncWork);  // onus of thread mgmt is
                                         // on implementer of
					 // the Standard Library

    int ret = fut.get();
    std::cout << "doAsyncWork() returned " << ret << std::endl;

    return 0;
}
