                               Things to Remember
                               ------------------

* Use std::weak_ptr for std::shared_ptr-like pointers that can dangle.

* Potential use cases for std::weak_ptr include caching, observer lists, and the
  prevention of std::shared_ptr cycles.
