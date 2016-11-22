/*
 * Extra code from the blog post [1].  This is the second version, with the
 * bugs removed.
 *
 * References:
 *
 *   [1] http://scottmeyers.blogspot.be/2016/11/help-me-sort-out-meaning-of-as.html
 */

#include <iostream>
#include <initializer_list>
  
class DefCtor {
  int x;
public:
  DefCtor(){}
  //explicit DefCtor(){}  // gcc rejects this...
};
  
class DeletedDefCtor {
  int x;
public:
  DeletedDefCtor() = delete;
};
  
class NoDefCtor {
  int x;    
public:
  NoDefCtor(int){}
};
  
template<typename T>
class X {
public:
  X() { std::cout << "Def Ctor\n"; }
      
  X(std::initializer_list<T> il)
  {
    std::cout << "il.size() = " << il.size() << '\n';
  }
};
  
int main()
{
  X<DefCtor> a0({});           // il.size = 0
  X<DefCtor> b0{{}};           // il.size = 1
      
  X<DeletedDefCtor> a2({});    // il.size = 0
  //X<DeletedDefCtor> b2{{}};    // error! attempt to use deleted constructor
  
  X<NoDefCtor> a1({});         // il.size = 0
  X<NoDefCtor> b1{{}};         // il.size = 0
}
