#include <thread>

class ThreadRAII {
public:
  enum class DtorAction { join, detach };         // see Item 10 for
                                                  // enum class info

  ThreadRAII(std::thread&& t, DtorAction a)       // in dtor, take
  : action(a), t(std::move(t)) {}                 // action a on t

  ~ThreadRAII()
  {                                               // see below for
    if (t.joinable()) {                           // joinability test

      if (action == DtorAction::join) {
        t.join();
      } else {
        t.detach();
      }

    }
  }

  ThreadRAII(ThreadRAII&&) = default;             // support
  ThreadRAII& operator=(ThreadRAII&&) = default;  // moving

  std::thread& get() { return t; }                // see below
  
private:
  DtorAction action;
  std::thread t;
};
