                               Things to Remember
                               ------------------

* std::unique_ptr is a small, fast, move-only smart pointer for managing
  resources with exclusive-ownership semantics.

* By default, resource destruction takes place via delete, but custom deleters
  can be specified.  Stateful deleters and function pointers as deleters
  increase the size of std::unique_ptr objects.

* Converting a std::unique_ptr to a std::shared_ptr is easy.
