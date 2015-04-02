/*
 * Key Idea:
 *
 *   If a new value is added to an enum that is included
 *   everywhere, the entire system will have to be recompiled.
 */

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              // audited = 500,
              indeterminate = 0xFFFFFFFF
            };
