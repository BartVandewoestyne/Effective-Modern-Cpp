                               Things to Remember
                               ------------------

* std::move performs an unconditional cast to an rvalue.  In and of itself, it
  doesn't move anything.

* std::forward casts it argument to an rvalue only if that argument is bound to
  an rvalue.

* Neither std::move nor std::forward do anything at runtime.
