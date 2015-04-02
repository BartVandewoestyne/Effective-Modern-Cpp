/*
 * Key idea
 *
 *   Compilers typically offer no help in identifying inconsistencies between
 *   function implementations and their exception specifications.
 */

void setup() {};
void cleanup() {};

void doWork() noexcept
{
  setup();     // set up work to be done

  // ...       // do the actual work

  cleanup();   // perform cleanup actions
}


int main()
{
  doWork();
}
