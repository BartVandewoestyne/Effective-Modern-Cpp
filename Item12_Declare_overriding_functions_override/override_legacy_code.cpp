/*
 * Key idea:
 *   The keyword override is reserved, but only in certain contexts.  It has a
 *   reserved meaning only when it occurs at the end of a member function
 *   declaration.  That means that if you have legacy code that already uses the
 *   name override, you don't need to change it for C++11.
 */
class Warning {     // potential legacy class from C++98
public:
  void override();  // legal in both C++98 and C++11
                    // (with the same meaning)
};
