/*
 * Key Idea:
 *
 *   Here an unscoped enum is used to reference a field in a
 *   std::tuple - an improvement to numbered fields.
 *
 *   Since std::get requires a size_t, here we can take
 *   advantage of implicit conversion which would have otherwise
 *   be more effort using scoped enums.
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

int main()
{

  enum UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<uiEmail>(uInfo);  // ah, get value of
                                        // email field
}
