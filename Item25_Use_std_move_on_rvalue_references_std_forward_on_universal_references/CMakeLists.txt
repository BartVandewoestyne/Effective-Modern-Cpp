SET(SRC_FILES_Cxx11
    dont_use_move_with_urefs.cpp
    dont_use_move_with_urefs_solution.cpp
    rrefs_are_moveable.cpp
    urefs_maybe_moveable.cpp
    reduce_and_copy.cpp
    matrix.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")

add_executable(dont_use_move_with_urefs dont_use_move_with_urefs.cpp)
add_executable(dont_use_move_with_urefs_solution dont_use_move_with_urefs_solution.cpp)

add_library(item25 rrefs_are_moveable.cpp
                   urefs_maybe_moveable.cpp
# TODO             move_or_forward_only_on_final_use.cpp
                   reduce_and_copy.cpp
                   matrix.cpp
                   return_value_optimization.cpp
                   )
