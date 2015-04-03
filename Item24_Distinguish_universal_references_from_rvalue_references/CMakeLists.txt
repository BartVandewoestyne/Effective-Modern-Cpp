# TODO: use Boost TypeIndex instead.
include_directories(../../3rd_party)

set_source_files_properties(record_time.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(urefs_initialization urefs_initialization.cpp)
add_executable(urefs_form urefs_form.cpp)

add_library(item24 rrefs_examples.cpp
                   urefs_contexts.cpp
                   no_type_deduction.cpp
                   record_time.cpp)
