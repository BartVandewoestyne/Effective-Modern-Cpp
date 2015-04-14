#include_directories(../../utils)

add_executable(refs_to_refs1
               refs_to_refs.cpp)
#target_link_libraries(refs_to_refs effc++11)

add_executable(reference_collapsing_contexts01
               reference_collapsing_contexts01.cpp)

add_executable(reference_collapsing_contexts02
               reference_collapsing_contexts02.cpp)
