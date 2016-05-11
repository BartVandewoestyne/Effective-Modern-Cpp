SET(NAMES_SAMPLES
    pointer_overload
    code_clarity
    template_example_flat
    template_example_templatized
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

subitem_add_executable(
  NAME template_example_templatized_cpp14
  SRC template_example_templatized_cpp14.cpp
  ADD_FLAG_FOR_CXX_14
)
