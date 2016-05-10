# TODO: complete this CMakeLists.txt

add_executable(expensive_int expensive_int.cpp)

add_executable(undefined_behavior undefined_behavior.cpp)

# pas très propre, faudrait une version avec cmake ...
target_link_libraries(undefined_behavior pthread)

#add_library(roots Polynomial.cpp)
