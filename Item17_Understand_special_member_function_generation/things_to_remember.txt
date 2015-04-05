                               Things to Remember
                               ------------------

* The special member functions are those compilers may generate on their own:
  default constructor, destructor, copy operations, and move operations.

* Move operations are generated only for classes lacking explicitly declared
  move operations, copy operations, and a destructor.

* The copy constructor is generated only for classes lacking an explicitly
  declared copy constructor, and it's deleted if a move operation is declared.
  The copy assignment operator is generated only for classes lacking an
  explicitly declared copy assignment operator, and it's deleted if a move
  operation is declared.  Generation of the copy operations in classes with an
  explicitly declared destructor is deprecated.

* Member function templates never suppress generation of special member
  functions.
