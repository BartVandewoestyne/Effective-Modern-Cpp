SET(NAMES_SAMPLES
  runtime_output01
  runtime_output02
)
SET(FLAGS_FOR_SAMPLES
  ADD_FLAG_FOR_CXX_11
)
subitems_add_executables("${NAMES_SAMPLES}" "${FLAGS_FOR_SAMPLES}")

subitem_add_executable(
  NAME boost_type_index
  SRC boost_type_index.cpp
  ADD_FLAG_FOR_CXX_11
  USE_BOOST
)

subitem_add_library(
  NAME ide_editors
  SRC compiler_diagnostics.cpp
  ADD_FLAG_FOR_CXX_11
)
