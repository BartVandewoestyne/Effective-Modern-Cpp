using namespace std::placeholders;   // as above

auto betweenB =
  std::bind(std::logical_and<>(),            // C++14
              std::bind(std::less_equal<>(), lowVal, _1),
	      std::bind(std::less_equal<>(), _1, highVal));
