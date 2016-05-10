FIND_PACKAGE ( Threads REQUIRED )

add_executable(software_threads software_threads.cpp)
TARGET_LINK_LIBRARIES ( software_threads ${CMAKE_THREAD_LIBS_INIT} )

add_executable(task_based_approach task_based_approach.cpp)
TARGET_LINK_LIBRARIES ( task_based_approach ${CMAKE_THREAD_LIBS_INIT} )

add_executable(thread_based_approach thread_based_approach.cpp)
TARGET_LINK_LIBRARIES ( thread_based_approach ${CMAKE_THREAD_LIBS_INIT} )
