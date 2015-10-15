#include <future>
#include <thread>
#include <utility>

int calcValue() {};            // func to run

int main()
{                                   // begin block

     std::packaged_task<int()>      // wrap calcValue so it
       pt(calcValue);               // can run asynchronously
     
     auto fut = pt.get_future();    // get future for pt
     
     std::thread t(std::move(pt));  // run pt on t

     // ...                         // see below

}                                   // end block
