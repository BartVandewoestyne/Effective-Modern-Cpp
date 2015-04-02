/*
 * Key Idea:
 *
 *   Member function templates cannot be disabled by hiding them
 *   into private scope because it's a different access level.
 *
 *   Deleted functions can be outside the class (in namespace scope).
 */

class Widget {
public:

  // ...

  template<typename T>
  void processPointer(T* ptr)
  { }

private:
  // template<>                                    // error!
  // void processPointer<void>(void*);

};

template<>                                         // still
void Widget::processPointer<void>(void*) = delete; // public,
                                                   // but
                                                   // deleted
