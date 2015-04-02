/*
 * Key Idea:
 *
 *   MyAllocList<T>::type doesn't necessarily refer to a type. 
 *   Usage of a nested typedef renders it a dependent type, 
 *   (depending on what T is), and therefore the compiler requires
 *   preceding the template instantiation with typename.
 */

// TODO: get this to compile!
#include "linked_list_synonym_with_alias_template01.cpp"

class Wine { };

template<>                      // MyAllocList specialization
class MyAllocList<Wine> {       // for when T is Wine
private:
  enum class WineType           // see Item 10 for info on
  { White, Red, Blush };        // "enum class"

  WineType type;                // in this class, type is
  // ...                        // a data member!
};
