/** Key idea:
 *
 *    TODO
 *
 */

#include <future>

using namespace std::literals;
 

void f()
{
    std::this_thread::sleep_for(1s);
}


int main()
{
    auto fut = std::async(f);          // as above
    
    if (fut.wait_for(0s) ==            // if task is
        std::future_status::deferred)  // deferred...
    {
                            // ...use wait or get on fut
                            // to call f synchronously

    } else {                // task isn't deferred

        while (fut.wait_for(100ms) !=      // infinite loop not
             std::future_status::ready) {  // possible (assuming
                                           // f finishes)

                              // task is neither deferred nor ready,
                              // so do concurrent work until it's ready
        }

        // ...                // fut is ready
    }
}
