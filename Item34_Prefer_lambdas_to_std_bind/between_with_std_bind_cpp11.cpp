auto betweenB =                              // C++11 version
  std::bind(std::logical_and<bool>(),
              std::bind(std::less_equal<int>(), lowVal, _1),
	      std::bind(std::less_equal<int>(), _1, highVal));
