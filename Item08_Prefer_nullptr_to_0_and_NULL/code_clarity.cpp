/*
 * Key Idea:
 *
 *   Using nullptr improves code clarity especially when auto variables are
 *   involved.
 */

int* findRecord() {
  return nullptr;
}

int main()
{

  {
    auto result = findRecord( /* arguments */ );
    
    if (result == 0) {
    }
  }


  {
    auto result = findRecord( /* arguments */ );

    if (result == nullptr) {
    }
  }

}
