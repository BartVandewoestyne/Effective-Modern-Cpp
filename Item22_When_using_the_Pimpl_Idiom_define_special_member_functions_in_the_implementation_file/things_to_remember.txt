                               Things to Remember
                               ------------------

* The Pimpl idiom decreases build times by reducing compilation dependencies
  between class clients and class implementations.

* For std::unique_ptr pImpl pointers, declare special member functions in the
  class header, but implement them in the implementation file.  Do this even if
  the default function implementations are acceptable.

* The above advice applies to std::unique_ptr, but not to std::shared_ptr.
