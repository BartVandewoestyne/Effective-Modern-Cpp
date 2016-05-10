FIND_PACKAGE ( Threads REQUIRED )

add_executable(default_launch_policy default_launch_policy.cpp)
# pas très propre, faudrait une version avec cmake ...
TARGET_LINK_LIBRARIES ( default_launch_policy ${CMAKE_THREAD_LIBS_INIT} )

add_executable(guaranteeing_truly_asynchronous_execution guaranteeing_truly_asynchronous_execution.cpp)
# pas très propre, faudrait une version avec cmake ...
TARGET_LINK_LIBRARIES ( guaranteeing_truly_asynchronous_execution ${CMAKE_THREAD_LIBS_INIT} )

add_executable(interesting_implications interesting_implications.cpp)
# pas très propre, faudrait une version avec cmake ...
TARGET_LINK_LIBRARIES ( interesting_implications ${CMAKE_THREAD_LIBS_INIT} )

add_executable(really_async_cpp11 really_async_cpp11.cpp)
TARGET_LINK_LIBRARIES ( really_async_cpp11 ${CMAKE_THREAD_LIBS_INIT} )

set_source_files_properties(really_async_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(really_async_cpp14 really_async_cpp14.cpp)
TARGET_LINK_LIBRARIES ( really_async_cpp14 ${CMAKE_THREAD_LIBS_INIT} )

add_executable(thread_local_storage thread_local_storage.cpp)
TARGET_LINK_LIBRARIES ( thread_local_storage ${CMAKE_THREAD_LIBS_INIT} )

# url: http://stackoverflow.com/questions/35856969/chrono-literals-is-not-a-namespace-name
set_source_files_properties(wait-based_loops.cpp PROPERTIES COMPILE_FLAGS "-std=gnu++14 -std=c++14")
add_executable(wait-based_loops wait-based_loops.cpp)
TARGET_LINK_LIBRARIES ( wait-based_loops ${CMAKE_THREAD_LIBS_INIT} )

set_source_files_properties(wait-based_loops_fixed.cpp PROPERTIES COMPILE_FLAGS "-std=gnu++14 -std=c++14")
add_executable(wait-based_loops_fixed wait-based_loops_fixed.cpp)
TARGET_LINK_LIBRARIES ( wait-based_loops_fixed ${CMAKE_THREAD_LIBS_INIT} )
