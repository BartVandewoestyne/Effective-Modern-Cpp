/*
 * Key idea:
 *
 *   In C++14, a seemingly trivial change in the way you write a return
 *   statement can affect the deduced type for a function.
 */

decltype(auto) f1()
{
  int x = 0;
  // ...
  return x;  // decltype(x) is int, so f1 returns int
}

decltype(auto) f2()
{
  int x = 0;
  // ...
  return (x);  // decltype((x)) is int&, so f2 returns int&
}
