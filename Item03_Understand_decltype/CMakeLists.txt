## TODO: check C++14 code!
subitem_add_executable(
  NAME decltype_for_complicated_lvalues
  SRC decltype_for_complicated_lvalues.cpp
)

subitem_add_library(
  NAME item02
  SRC problem.cpp typical_cases.cpp string_deque.cpp
      # decltype_auto_for_function_return_types_cpp14.cpp
      # return_statements_cpp14.cpp
  ADD_FLAG_FOR_CXX_11
)
