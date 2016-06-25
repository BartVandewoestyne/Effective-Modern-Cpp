set_source_files_properties(insertion_cpp14.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

add_executable(insertion_cpp98 insertion_cpp98.cpp)
# TODO: find out why this doesn't compile!!! add_executable(insertion_cpp11 insertion_cpp11.cpp)
add_executable(insertion_cpp14 insertion_cpp14.cpp)
