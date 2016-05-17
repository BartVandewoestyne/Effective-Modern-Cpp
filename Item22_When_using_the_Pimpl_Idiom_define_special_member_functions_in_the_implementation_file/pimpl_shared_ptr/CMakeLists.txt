SET(SRC_FILES_Cxx11
    widget.cpp
    client.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")

include_directories(../)

add_library(widget_pimpl_shared_ptr widget.cpp)

add_executable(client_pimpl_shared_ptr client.cpp)
target_link_libraries(client_pimpl_shared_ptr widget_pimpl_shared_ptr)
