/*
 * Key Idea:
 *
 *   In C++98 style enums, the names of these unscoped enumerators belong to the
 *   scope containing the enum, and that means nothing else in that scope may
 *   have the same name:
 */

enum Color { black, white, red };  // black, white, red are
                                   // in same scope as Color

//auto white = false;                // error! white already
                                   // declared in this scope
