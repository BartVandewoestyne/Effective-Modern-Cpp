                               Things to Remember
                               ------------------

* std::shared_ptrs offer convenience approaching that of garbage collection for
  the shared lifetime management of arbitrary resources.

* Compared to std::unique_ptr, std::shared_ptr objects are typically twice as
  big, incur overhead for control blocks, and require atomic reference count
  manipulations.

* Default resource destruction is via delete, but custom deleters are supported.
  The type of the deleter has no effect on the type of the std::shared_ptr.

* Avoid creating std::shared_ptrs from variables of raw pointer type.
