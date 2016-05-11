SET(NAMES_SAMPLES
  constructor_overload_resolution
  initialization_values
  initializer_lists1
  initializer_lists2
  initializer_lists3
  initializer_lists4
  parenthesis_braces_in_templates
)
SET(FLAGS_FOR_SAMPLES
  ADD_FLAG_FOR_CXX_11
)

subitems_add_executables("${NAMES_SAMPLES}" "${FLAGS_FOR_SAMPLES}")
