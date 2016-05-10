set_source_files_properties(init_capture_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(init_capture_cpp14
               init_capture_cpp14.cpp)

set_source_files_properties(init_capture_cpp11.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(init_capture_cpp11
               init_capture_cpp11.cpp
               Widget.cpp)

set_source_files_properties(move_capture1_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(move_capture1_cpp14
               move_capture1_cpp14.cpp)

add_executable(move_capture1_cpp11
               move_capture1_cpp11.cpp)

set_source_files_properties(move_capture2.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(move_capture2
               move_capture2.cpp)

