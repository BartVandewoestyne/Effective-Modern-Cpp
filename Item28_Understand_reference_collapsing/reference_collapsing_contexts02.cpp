/*
 * Key idea:
 *
 *   The third context in which reference collapsing occurs  is the generation
 *   and use of typedefs and alias declarations.  If, during creation or
 *   evaluation of a typedef, references to references arise, reference
 *   collapsing intervenes to eliminate them.
 */

#include "reference_collapsing_contexts02.h"

int main()
{
    Widget<int&> w;
}
