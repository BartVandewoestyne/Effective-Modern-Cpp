add_executable(default_launch_policy default_launch_policy.cpp)
target_link_libraries(default_launch_policy ${CMAKE_THREAD_LIBS_INIT})

add_executable(guaranteeing_truly_asynchronous_execution guaranteeing_truly_asynchronous_execution.cpp)
target_link_libraries(guaranteeing_truly_asynchronous_execution ${CMAKE_THREAD_LIBS_INIT})

add_executable(interesting_implications interesting_implications.cpp)
target_link_libraries(interesting_implications ${CMAKE_THREAD_LIBS_INIT})

add_executable(really_async_cpp11 really_async_cpp11.cpp)
target_link_libraries(really_async_cpp11 ${CMAKE_THREAD_LIBS_INIT})

set_source_files_properties(really_async_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(really_async_cpp14 really_async_cpp14.cpp)
target_link_libraries(really_async_cpp14 ${CMAKE_THREAD_LIBS_INIT})

add_executable(thread_local_storage thread_local_storage.cpp)
target_link_libraries(thread_local_storage ${CMAKE_THREAD_LIBS_INIT})

set_source_files_properties(wait-based_loops.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(wait-based_loops wait-based_loops.cpp)
target_link_libraries(wait-based_loops ${CMAKE_THREAD_LIBS_INIT})

set_source_files_properties(wait-based_loops_fixed.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")
add_executable(wait-based_loops_fixed wait-based_loops_fixed.cpp)
target_link_libraries(wait-based_loops_fixed ${CMAKE_THREAD_LIBS_INIT})
