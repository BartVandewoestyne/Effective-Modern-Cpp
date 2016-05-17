#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <functional>

#include <iostream>

// url: http://enki-tech.blogspot.fr/2012/08/c11-generic-singleton.html
template <class T>
class Singleton
{
public:
  template <typename... Args>
  static
  T* get_instance(Args... args)
  {
    if (!instance_)
      {
        instance_ = new T(std::forward<Args>(args)...);
      }

    return instance_;
  }

  static
  void destroy_instance()
  {
    delete instance_;
    instance_ = nullptr;
  }

private:
  static T* instance_;
};

template <class T> T*  Singleton<T>::instance_ = nullptr;

class Filters: public Singleton<Filters>
{
  friend class Singleton<Filters>;

private:
  Filters() {}

public:
  using FilterContainer =                    // see Item 9 for
  std::vector<std::function<bool(int)>>;   // "using", Item 2
  // for std::function

  FilterContainer filters;
};

// filtering funcs

#endif /* UTILS_H */
