include_directories(../)

add_library(widget_pimpl_shared_ptr widget.cpp)

add_executable(client_pimpl_shared_ptr client.cpp)
target_link_libraries(client_pimpl_shared_ptr widget_pimpl_shared_ptr)
