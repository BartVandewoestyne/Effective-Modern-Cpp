SET(NAMES_SAMPLES
  pinch_of_pseudocode
  case1_const
  case1_non_const
  case1_pointer
  case3_pass_by_value
  array-to-pointer_decay_rule
  arrays_by_value
  arrays_by_reference
  function-to-pointer_decay_rule
)
subitems_add_executables("${NAMES_SAMPLES}" "")

subitem_add_executable(NAME case2_uref SRC case2_uref.cpp ADD_FLAG_FOR_CXX_11)

subitem_add_library(
  NAME item01
  SRC deduce_nb_array_elements.cpp array_and_pointer_parameter_equivalence.cpp
  ADD_FLAG_FOR_CXX_11
)
