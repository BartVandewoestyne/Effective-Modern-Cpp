# TODO: complete this CMakeLists.txt

add_executable(expensive_int expensive_int.cpp)

add_executable(undefined_behavior undefined_behavior.cpp)
FIND_PACKAGE ( Threads REQUIRED )
TARGET_LINK_LIBRARIES ( undefined_behavior ${CMAKE_THREAD_LIBS_INIT} )

#add_library(roots Polynomial.cpp)
