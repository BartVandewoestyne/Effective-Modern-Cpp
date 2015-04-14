/*
 * Key idea:
 *
 *   Even types with explicit move support may not benefit as much as you'd
 *   hope.  All containers in the standard C++11 library support moving, for
 *   example, but it would be a mistake to assume that moving all containers is
 *   cheap.  For some containers, this is because there's no truly cheap way to
 *   move their contents.  For others, it's because the truly cheap move
 *   operations the containers offer come with caveats the container elements
 *   can't satisfy.
 *
 * TODO: time this.
 */

#include <array>
#include <vector>

class Widget {};

int main()
{
    std::vector<Widget> vw1;

    // ...                      // put data into vw1

    auto vw2 = std::move(vw1);  // move vw1 into vw2.  Runs in
                                // constant time.  Only ptrs
                                // in vw1 and vw2 are modified


    std::array<Widget, 10000> aw1;

    // ...                      // put data into aw1

    auto aw2 = std::move(aw1);  // move aw1 into aw2.  Runs in
                                // linear time.  All elements in
                                // aw1 are moved into aw2.
}
