/*
 * Key idea:
 *
 *   Use std::weak_ptr for std::shared_ptr-like pointers that can dangle.
 */

#include <memory>
#include <unordered_map>

class Widget {};

//class WidgetID {};
typedef int WidgetID;

std::unique_ptr<const Widget> loadWidget(WidgetID id)
{
  return nullptr;
}

std::shared_ptr<const Widget> fastLoadWidget(WidgetID id)
{
  static std::unordered_map<WidgetID,
                            std::weak_ptr<const Widget>> cache;

  auto objPtr = cache[id].lock();   // objPtr is std::shared_ptr
                                    // to cached object (or null
                                    // if object's not in cache)

  if (!objPtr) {                    // if not in cache,
    objPtr = loadWidget(id);        // load it
    cache[id] = objPtr;             // cache it
  }
  return objPtr;
}

int main()
{

  auto spw =                      // after spw is constructed,
    std::make_shared<Widget>();   // the pointed-to Widget's
                                  // ref count (RC) is 1. (See
                                  // Item 21 for info on
                                  // std::make_shared.)
  
  // ...
  
  std::weak_ptr<Widget> wpw(spw);  // wpw points to same Widget
                                   // as spw.  RC remains 1
  
  // ...
  
  spw = nullptr;                   // RC goes to 0, and the
                                   // Widget is destroyed.
                                   // wpw now dangles

  if (wpw.expired()) {             // if wpw doesn't point
  }                                // to an object...

  std::shared_ptr<Widget> spw1 = wpw.lock();  // if wpw's expired,
                                              // spw1 is null

  auto spw2 = wpw.lock();                     // same as above,
                                              // but uses auto

  std::shared_ptr<Widget> spw3(wpw);  // if wpw's expired,
                                      // throw std::bad_weak_ptr
}
