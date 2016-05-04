add_executable(runtime_output01 runtime_output01.cpp)
add_executable(runtime_output02 runtime_output02.cpp)
add_executable(boost_type_index boost_type_index.cpp)

add_library(ide_editors.cpp
            compiler_diagnostics.cpp)

# TODO: probably requires Boost 1.56, and CMake needs to check if this is
# available.
find_package(Boost 1.56 REQUIRED)
target_link_libraries(boost_type_index ${Boost_LIBRARIES})
