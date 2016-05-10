# TODO: improve this CMakeLists.txt file.
FIND_PACKAGE ( Threads REQUIRED )

add_library(item38_example1 example1.cpp)
TARGET_LINK_LIBRARIES ( item38_example1 ${CMAKE_THREAD_LIBS_INIT} )

add_executable(item38_example2 example2.cpp)
TARGET_LINK_LIBRARIES ( item38_example2 ${CMAKE_THREAD_LIBS_INIT} )
