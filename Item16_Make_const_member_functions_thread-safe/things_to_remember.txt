                               Things to Remember
                               ------------------

* Make const member functions thread safe unless you're certain they'll never be
  used in a concurrent context.

* use of std::atomic variables may offer better performance than a mutex, but
  they're suited for manipulation of only a single variable or memory location.
