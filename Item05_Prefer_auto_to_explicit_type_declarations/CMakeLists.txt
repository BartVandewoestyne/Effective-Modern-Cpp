#TODO: wait until clang bug fixed!!! add_executable(auto auto.cpp)

subitem_add_library(
  NAME simple_joys
  SRC simple_joys.cpp
  ADD_FLAG_FOR_CXX_11
)
