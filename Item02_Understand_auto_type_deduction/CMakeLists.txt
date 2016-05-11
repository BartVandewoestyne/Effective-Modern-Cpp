subitem_add_executable(
  NAME auto_type_deduction
  SRC auto_type_deduction.cpp
  ADD_FLAG_FOR_CXX_11)

subitem_add_executable(
  NAME auto_deduction_vs_template_deduction
  SRC auto_deduction_vs_template_deduction.cpp
  ADD_FLAG_FOR_CXX_11)

subitem_add_executable(
  NAME function_return_type_deduction
  SRC function_return_type_deduction.cpp
  ADD_FLAG_FOR_CXX_14)
