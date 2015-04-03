/*
 * Key idea:
 *
 *   std::make_unique is not part of C++11, but a basic version of it is easy
 *   to write yourself.
 */

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
