/*
 * Key Idea:
 *
 *   All the headers of the data member types must
 *   be included in order for this code to compile.
 *   If an included header's content changes, clients
 *   of this code must recompile.
 */

#include <string>
#include <vector>
#include "gadget.h"

class Widget {              // in header widget.h
public:
  Widget();
  // ...

private:
  std::string name;
  std::vector<double> data;
  Gadget g1, g2, g3;        // Gadget is some user-
};                          // defined type
