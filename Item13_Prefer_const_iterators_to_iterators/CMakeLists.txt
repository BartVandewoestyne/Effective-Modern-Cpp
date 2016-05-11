add_executable(insertion_cpp98 insertion_cpp98.cpp)

subitem_add_executable(
  NAME insertion_cpp11
  SRC insertion_cpp11.cpp
  ADD_FLAG_FOR_CXX_11
)

subitem_add_executable(
  NAME insertion_cpp14
  SRC insertion_cpp14.cpp
  ADD_FLAG_FOR_CXX_14
)
