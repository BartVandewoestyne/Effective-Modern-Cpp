set_source_files_properties(auto.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

#TODO: wait until clang bug fixed!!! add_executable(auto auto.cpp)

add_library(simple_joys simple_joys.cpp)
