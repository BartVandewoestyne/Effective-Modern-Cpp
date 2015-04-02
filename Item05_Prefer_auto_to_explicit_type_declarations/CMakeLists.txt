set_source_files_properties(auto.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

add_executable(auto auto.cpp)

add_library(simple_joys simple_joys.cpp)
