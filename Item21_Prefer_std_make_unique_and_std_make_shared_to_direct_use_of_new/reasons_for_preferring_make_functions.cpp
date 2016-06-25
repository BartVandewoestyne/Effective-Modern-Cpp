/*
 * Key ideas:
 *
 *   - Using std::make_unique and std::make_shared is preferable because you
 *     don't have to repeat the type begin created.
 *
 *   - Using std::make_unique and std::make_shared is more exception safe.
 *
 *   - A special feature of std::make_shared is improved efficiency.
 */

#include <iostream>
#include <memory>
#include <vector>

class Widget {};

void processWidget(std::shared_ptr<Widget> spw, int priority)
{
  std::cout << "Processing Widget... done." << std::endl;
}

int computePriority()
{
  std::cout << "Computing priority... done." << std::endl;
}


int main()
{

  // Reason 1: no need to type the type twice.
  
  auto upw1(std::make_unique<Widget>());       // with make func
  
  std::unique_ptr<Widget> upw2(new Widget());  // without make func
  
  
  auto spw1(std::make_shared<Widget>());       // with make func
  
  std::shared_ptr<Widget> spw2(new Widget());  // without make func


  // Reason 2: using the make_* versions is more exception safe.

  processWidget(std::shared_ptr<Widget>(new Widget),  // potential
                computePriority());                   // resource
                                                      // leak!

  processWidget(std::make_shared<Widget>(),           // no potential
                computePriority());                   // resource leak


  // Reason 3: a special feature of make_shared is improved efficiency.
  {
    std::shared_ptr<Widget> spw(new Widget);
  }
  {
    auto spw = std::make_shared<Widget>();
  }

}
