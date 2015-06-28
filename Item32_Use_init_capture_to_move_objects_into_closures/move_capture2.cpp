/**
 * Key idea:
 *
 *   Example demonstrating how to use std::bind to emulate move capture.
 */

#include <functional>
#include <memory>
#include <utility>

#include "Widget.h"

int main()
{
    { // C++14 version

      auto func = [pw = std::make_unique<Widget>()]  // as before,
                  { return pw->isValidated()         // create pw
                           && pw->isArchived(); };   // in closure
    }

    { // C++11 emulation
      auto func = std::bind(
                    [](const std::unique_ptr<Widget>& pw)
                    { return pw->isValidated()
                             && pw->isArchived(); },
                    std::make_unique<Widget>()       // REMARK: this is C++14!!!
                  );
    }
}
