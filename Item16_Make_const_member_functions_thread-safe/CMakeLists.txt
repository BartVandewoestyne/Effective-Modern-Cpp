# TODO: complete this CMakeLists.txt

add_executable(expensive_int expensive_int.cpp)

add_executable(undefined_behavior undefined_behavior.cpp)
target_link_libraries(undefined_behavior ${CMAKE_THREAD_LIBS_INIT})

#add_library(roots Polynomial.cpp)
