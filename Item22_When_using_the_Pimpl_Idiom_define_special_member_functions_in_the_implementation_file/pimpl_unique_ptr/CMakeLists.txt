include_directories(../)

set_source_files_properties(widget.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")

add_library(widget_pimpl_unique_ptr widget.cpp)

add_executable(client_pimpl_unique_ptr client.cpp)
target_link_libraries(client_pimpl_unique_ptr widget_pimpl_unique_ptr)
