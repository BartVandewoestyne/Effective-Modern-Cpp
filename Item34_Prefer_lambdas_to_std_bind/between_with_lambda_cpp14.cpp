auto betweenL =
  [lowVal, highVal]
  (const auto& val)                            // C++14
  { return lowVal <= val && val <= highVal; };
