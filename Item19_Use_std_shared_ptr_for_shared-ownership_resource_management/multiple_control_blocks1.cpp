#include <memory>
#include <vector>

class Widget {
public:
  void process();
};

std::vector<std::shared_ptr<Widget>> processedWidgets;

void Widget::process()
{
  // ...                                  // process the widget

  processedWidgets.emplace_back(this);    // add it to list of
}                                         // processed Widgets;
                                          // this is wrong!
