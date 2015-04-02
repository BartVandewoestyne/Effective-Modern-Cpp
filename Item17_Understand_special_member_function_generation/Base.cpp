/*
 * Key idea:
 *
 *   Unless a class inherits a destructor that's already virtual, the only way
 *   to make a destructor virtual is to explicitly declare it that way.  Often,
 *   the default implementation would be correct, and "=default" is a good way
 *   to express that.
 *   However, a user-declared destructor suppresses generation of the move operations, so
 *   if movability is to be supported, "=default" often finds a second
 *   application.
 *   Declaring the move operations disables the copy operations, so if
 *   copyability is also desired, one more round of "=default" does the job.
 */

class Base {
public
  virtual ~Base() = default;               // make dtor virtual

  Base(Base&&) = default;                  // support moving
  Base& operator=(Base&&) = default;

  Base(const Base&) = default;             // support copying
  Base& operator=(const Base&) = default;
};
