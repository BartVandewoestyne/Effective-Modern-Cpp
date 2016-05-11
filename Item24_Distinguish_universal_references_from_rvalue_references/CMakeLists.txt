SET(SRC_FILES_Cxx11
    rrefs_examples.cpp
    urefs_contexts.cpp
    no_type_deduction.cpp
    urefs_form.cpp
    urefs_initialization.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")

# TODO: use Boost TypeIndex instead.
include_directories(../../3rd_party)

add_std_cxx14_flag("record_time.cpp")

add_executable(urefs_initialization urefs_initialization.cpp)
add_executable(urefs_form urefs_form.cpp)

add_library(item24 rrefs_examples.cpp
                   urefs_contexts.cpp
                   no_type_deduction.cpp
                   record_time.cpp)
