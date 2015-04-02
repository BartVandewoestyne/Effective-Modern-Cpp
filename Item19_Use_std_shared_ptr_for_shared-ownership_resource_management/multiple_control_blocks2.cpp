#include <memory>
#include <vector>

class Widget : public std::enable_shared_from_this<Widget> {
public:
  void process();
};

std::vector<std::shared_ptr<Widget>> processedWidgets;

void Widget::process()
{
  // as before, process the Widget
  // ...

  // add std::shared_ptr to current object to processedWidgets
  processedWidgets.emplace_back(shared_from_this());
}
