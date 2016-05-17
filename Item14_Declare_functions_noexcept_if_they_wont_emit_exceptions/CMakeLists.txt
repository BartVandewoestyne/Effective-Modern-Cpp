subitem_add_library(
  NAME never_throw_exception
  SRC never_throw_exception.cpp
  ADD_FLAG_FOR_CXX_11
)

add_library(example_with_move example_with_move.cpp)

subitem_add_executable(
  NAME inconsistencies
  SRC inconsistencies.cpp
  ADD_FLAG_FOR_CXX_11
)
