SET(NAMES_SAMPLES
  runtime_output01
  runtime_output02
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

subitems_add_executables("boost_type_index" "ADD_FLAG_FOR_CXX_11;USE_BOOST")

subitem_add_library(NAME ide_editors SRC compiler_diagnostics.cpp ADD_FLAG_FOR_CXX_11)
