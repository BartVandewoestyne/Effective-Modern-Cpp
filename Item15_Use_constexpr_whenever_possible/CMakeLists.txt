set_source_files_properties(
    constexpr_variables.cpp
    constexpr_functions_cpp11.cpp
    constexpr_user-defined_types_cpp11.cpp
    Point_cpp11.h
    PROPERTIES COMPILE_FLAGS -std=c++11
)
set_source_files_properties(
    constexpr_functions_cpp14.cpp
    constexpr_user-defined_types_cpp14.cpp
    Point_cpp14.h
    PROPERTIES COMPILE_FLAGS -std=c++14
)

add_executable(constexpr_variables constexpr_variables.cpp)
add_executable(constexpr_functions_cpp11 constexpr_functions_cpp11.cpp)
add_executable(constexpr_functions_cpp14 constexpr_functions_cpp14.cpp)
add_executable(constexpr_user-defined_types_cpp11 constexpr_user-defined_types_cpp11.cpp)
add_executable(constexpr_user-defined_types_cpp14 constexpr_user-defined_types_cpp14.cpp)
