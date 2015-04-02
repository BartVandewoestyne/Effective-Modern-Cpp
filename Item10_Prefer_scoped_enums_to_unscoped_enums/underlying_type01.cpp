/*
 * Key Idea:
 *
 *   Every enum has an underlying type determined
 *   by the compiler - it may choose char, int, or
 *   any integral type.
 */

enum Color { black, white, red };

enum Status { good = 0,
              failed = 1,
              incomplete = 100,
              corrupt = 200,
              indeterminate = 0xFFFFFFFF
            };
