/*
 * Key Idea:
 *
 *   Forward declaration of enums removes the dependency
 *   on the enum definition.
 */

enum class Status;                  // forward declaration
void continueProcessing(Status s);  // use of fwd-declared enum
