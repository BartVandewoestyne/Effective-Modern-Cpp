/*
 * Key ideas:
 *
 *   - Using std::make_unique and std::make_shared is preferable because you
 *     don't have to repeat the type begin created.
 *
 *   - Using std::make_unique and std::make_shared is more exception safe.
 *
 *   - A special feature of std::make_shared is improved efficiency.
 */

// TODO: this doesn't compile yet, make it to compile!

#include <iostream>
#include <memory>
#include <vector>

class Widget {};

class ReallyBigType { /* ... */ };

void processWidget(std::shared_ptr<Widget> spw, int priority)
{
  std::cout << "Processing Widget... done." << std::endl;
}

int computePriority()
{
  std::cout << "Computing priority... done." << std::endl;
}

void cusDel(Widget *ptr)                        // custom
{                                               // deleter
  std::cout << "Custom deleter." << std::endl;
}

int main()
{

  // Limitation 1: none of the make functions permit the specification of custom deleters.

  auto widgetDeleter = [](Widget* pw) { /* ... */ };
  
  std::unique_ptr<Widget, decltype(widgetDeleter)>
    upw(new Widget(), widgetDeleter);
  
  std::shared_ptr<Widget> spw(new Widget(), widgetDeleter);


  // Limitation 2: within the make function, the perfect forwarding code uses
  // parentheses, not braces.  The bad news of this is that if you want to
  // construct your pointed-to object using a braced initializer, you must use
  // new directly.

  {
    auto upv = std::make_unique<std::vector<int>>(10,20);
    auto spv = std::make_shared<std::vector<int>>(10,20);
  }
  {
    // create std::initializer_list
    auto initList = {10, 20};

    // create std::vector using std::initializer_list ctor
    auto spv = std::make_shared<std::vector<int>>(initList);
  }


  // Limitation 3 (only for make_shared)
  auto pBigObj =                         // create very large
    std::make_shared<ReallyBigType>();   // object via
                                         // std::make_shared
  
               // create std::shared_ptrs and std::weak_ptrs to
               // large object, use them to work with it
  
               // final std::shared_ptr to object destroyed here,
               // but std::weak_ptrs to it remain
  
               // during this period, memory formerly occupied
               // by large object remains allocated
  
               // final std::weak_ptr to object destroyed here;
               // memory for control block and object is released

  std::shared_ptr<ReallyBigType> pBigObj(new ReallyBigType);
                                       // create very large
                                       // object via new

               // as before, create std::shared_ptrs and
               // std::weak_ptrs to object, use them with it

               // final std::shared_ptr to object destroyed here,
               // but std::weak_ptrs to it remain
               // memory for object is deallocated

               // during this period, only memory for
               // the control block remains allocated

               // final std::weak_ptr to object destroyed here;
               // memory for control block and object is released


  // Exception-unsafe call

  processWidget(                                  // as before
    std::shared_ptr<Widget>(new Widget, cusDel),  // potential
    computePriority()                             // resource
  );                                              // leak!


  // Exception-safe calls

  std::shared_ptr<Widget> spw(new Widget, cusDel);

  processWidget(spw, computePriority());      // correct, but not
                                              // optimal; see below

  processWidget(std::move(spw),               // both efficient and
                computePriority());           // exception safe

}
