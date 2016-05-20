# TODO: improve this CMakeLists.txt file.

add_library(item38_example1 example1.cpp)
target_link_libraries(item38_example1 pthread)

add_executable(item38_example2 example2.cpp)
target_link_libraries(item38_example2 pthread)
