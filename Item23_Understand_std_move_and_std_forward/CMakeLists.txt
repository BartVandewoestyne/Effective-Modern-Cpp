SET(SRC_FILES_Cxx11
    std_move_in_cpp11.cpp
    annotation.cpp
    move_constructor_with_move.cpp
    move_constructor_with_forward.cpp
    typical_use_of_std_forward.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")
add_std_cxx14_flag("std_move_in_cpp14.cpp")

add_executable(typical_use_of_std_forward
               typical_use_of_std_forward.cpp)

add_library(item23 std_move_in_cpp11.cpp
                   std_move_in_cpp14.cpp
                   annotation.cpp
                   move_constructor_with_move.cpp
                   move_constructor_with_forward.cpp)
