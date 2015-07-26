#include "compress.h"

Widget w;

using namespace std::placeholders;

auto compressRateB = std::bind(compress, w, _1);

int main()
{
    compressRateB(CompLevel::High);    // how is arg
                                       // passed?
}
