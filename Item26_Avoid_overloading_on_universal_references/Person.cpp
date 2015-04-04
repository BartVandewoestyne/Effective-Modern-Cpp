/*
 * Key idea:
 *
 *   TODO
 */

#include <iostream>
#include <string>

std::string nameFromIdx(int idx)  // return std::string
{                                 // corresponding to idx
    std::string s("Test");
    return s;
}

class Person {
public:

  //Person() = default;

  template<typename T>
  explicit Person(T&& n)          // perfect forwarding ctor;
  : name(std::forward<T>(n)) {    // initializes data member
    std::cout << "Person(T&&)" << std::endl;
  }

  explicit Person(int idx)        // int ctor
  : name(nameFromIdx(idx)) {
    std::cout << "Person(int idx)" << std::endl;
  }

  //Person(const Person& rhs);    // copy ctor
                                  // (compiler-generated)
  //Person(Person&&);             // move ctor
                                  // (compiler-generated)

private:
  std::string name;
};

//class SpecialPerson: public Person {
//public:
//  SpecialPerson(const SpecialPerson& rhs)  // copy ctor; calls
//  : Person(rhs)                            // base class
//  { /* ... */ }                            // forwarding ctor!
//
//  SpecialPerson(SpecialPerson&& rhs)       // move ctor; calls
//  : Person(std::move(rhs))                 // base class
//  { /* ... */ }                            // forwarding ctor!
//};


int main()
{
  {
    Person p("Nancy");

    //auto cloneOfP(p);             // create new Person from p;
                                    // this won't compile!
  }
  {
    const Person cp("Nancy");       // object is now const

    auto cloneOfP(cp);              // calls copy constructor!
  }
}
