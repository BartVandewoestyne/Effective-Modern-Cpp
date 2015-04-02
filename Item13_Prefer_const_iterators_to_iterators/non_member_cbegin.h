/*
 * Key idea:
 *
 *   If you're using C++11, you want to write maximally generic code, and none
 *   of the libraries you're using provides the missing templates for non-member
 *   cbegin and friends, you can throw your own implementations together with
 *   ease.
 */

template <class C>
auto cbegin(const C& container)->decltype(std::begin(container))
{
  return begin(container);    // see explanation below
}
