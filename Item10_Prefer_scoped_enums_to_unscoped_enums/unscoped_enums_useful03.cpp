/*
 * Key Idea:
 *
 *   The scoped enum method for referencing std::tuple
 *   field with an enum - requires a cast to size_t.
 *   Unscoped enums have an advantage here with implicit
 *   conversion.
 */

#include <string>
#include <tuple>

using UserInfo =               // type alias; see Item 9
  std::tuple<std::string,      // name
             std::string,      // email
             std::size_t> ;    // reputation

int main()
{

  enum class UserInfoFields { uiName, uiEmail, uiReputation };

  UserInfo uInfo;                       // as before
  // ...
  auto val = std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(uInfo);
}
