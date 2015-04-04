add_executable(dont_use_move_with_urefs dont_use_move_with_urefs.cpp)
add_executable(dont_use_move_with_urefs_solution dont_use_move_with_urefs_solution.cpp)

add_library(item25 rrefs_are_moveable.cpp
                   urefs_maybe_moveable.cpp
# TODO             move_or_forward_only_on_final_use.cpp
                   reduce_and_copy.cpp
                   matrix.cpp
                   return_value_optimization.cpp
                   )
