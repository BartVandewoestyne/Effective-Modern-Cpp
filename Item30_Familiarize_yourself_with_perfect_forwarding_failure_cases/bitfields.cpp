/*
 * Key idea:
 *
 *   A failure case for perfect forwarding is when a bitfield is used as a
 *   function argument.
 *
 *   The key to passing a bitfield into a perfect-forwarding function, is to
 *   take advantage of the fact that the forwarded-to function will always
 *   receive a copy of the bitfield's value.  You can thus make a copy yourself
 *   and call the forwarding function with the copy.
 */

#include <cstdint>
#include <utility>

struct IPv4Header {
  std::uint32_t version:4,
                IHL:4,
                DSCP:6,
                ECN:2,
                totalLength:16;
  // ...
};

void f(std::size_t sz) {}  // function to call

template<typename T>
void fwd(T&& param)             // accept any argument
{
  f(std::forward<T>(param));    // forward it to f
}

int main()
{
  IPv4Header h;
  // ...
  f(h.totalLength);          // fine

  //fwd(h.totalLength);      // error!


  // copy bitfield value; see Item 6 for info on init. form
  auto length = static_cast<std::uint16_t>(h.totalLength);

  fwd(length);               // forward the copy
}
