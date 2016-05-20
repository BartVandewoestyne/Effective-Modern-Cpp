set_source_files_properties(std_move_in_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(typical_use_of_std_forward
               typical_use_of_std_forward.cpp)

add_library(item23 std_move_in_cpp11.cpp
                   std_move_in_cpp14.cpp
                   annotation.cpp
                   move_constructor_with_move.cpp
                   move_constructor_with_forward.cpp)
