FIND_PACKAGE ( Threads REQUIRED )

add_executable(example1 example1.cpp)
TARGET_LINK_LIBRARIES ( example1 ${CMAKE_THREAD_LIBS_INIT} )

add_executable(example2 example2.cpp)
TARGET_LINK_LIBRARIES ( example2 ${CMAKE_THREAD_LIBS_INIT} )
