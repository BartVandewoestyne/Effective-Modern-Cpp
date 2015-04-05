                               Things to Remember
                               ------------------

* C++98-style enums are now known as unscoped enums.

* Enumerators of scoped enums are visible only within the enum.  They convert to
  other types only with a cast.

* Both scoped and unscoped enums support specification of the underlying type.
  The default underlying type for scoped enums is int.  Unscoped enums have no
  default underlying type.

* Scoped enums may always be forward-declared.  Unscoped enums may be
  forward-declared only if their declaration specifies an underlying type.
