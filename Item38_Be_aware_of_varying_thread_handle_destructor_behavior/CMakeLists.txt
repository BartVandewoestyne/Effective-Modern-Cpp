subitem_add_library(
  NAME item38_example1
  SRC example1.cpp
  ADD_FLAG_FOR_CXX_11
  USE_PTHREAD
)

subitem_add_executable(
  NAME item38_example2
  SRC example2.cpp
  ADD_FLAG_FOR_CXX_11
  USE_PTHREAD
)
#ps: execution result -> 'terminate called without an active exception'
