/**
 * Key idea:
 *
 *   - Software threads are a limited resource.  If you try to create more than the system
 *     can provide, a std::system_error exception is thrown.  This is true even if the function
 *     you want to run can't throw.
 */

#include <iostream>
#include <thread>
#include <vector>

int doAsyncWork() noexcept   // see Item 14 for noexcept
{
    std::cout << "doAsyncWork()" << std::endl;

    return 1;

}


int main()
{
    std::vector<std::thread> threads;

    unsigned int nr_threads = 10;  // increase this until you get a std::system_error exception...???

    for (unsigned int i = 0; i < nr_threads; ++i)
    {
        // TODO: why doesn't this work???
        //std::thread t(doAsyncWork);  // throws if no more
        //                             // threads are available
	//threads.push_back(t);

	threads.push_back(std::thread(doAsyncWork));
    }

    for (auto& t : threads)
    {
        t.join();
    }

    return 0;
}
