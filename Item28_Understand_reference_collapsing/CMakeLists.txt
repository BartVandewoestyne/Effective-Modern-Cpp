SET(SAMPLES_NAMES
    reference_collapsing_contexts01
    reference_collapsing_contexts02
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11")

#include_directories(../../utils)

add_executable(refs_to_refs1 refs_to_refs.cpp)
