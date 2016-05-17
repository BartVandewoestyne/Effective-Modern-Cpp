subitem_add_executable(
  NAME expensive_int
  SRC expensive_int.cpp
  ADD_FLAG_FOR_CXX_11
)

subitem_add_executable(
  NAME undefined_behavior
  SRC undefined_behavior.cpp
  ADD_FLAG_FOR_CXX_11
  USE_PTHREAD
)

#add_library(roots Polynomial.cpp)
