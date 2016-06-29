set_source_files_properties(
    typical_cases
    PROPERTIES COMPILE_FLAGS -std=c++98
)
set_source_files_properties(
    decltype_for_complicated_lvalues.cpp
    problem.cpp
    string_deque.cpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)
set_source_files_properties(
    decltype_auto_for_function_return_types_cpp14.cpp
    decltype_auto_for_normal_auto_variables_cpp14.cpp
    return_statements_cpp14.cpp
    PROPERTIES COMPILE_FLAGS -std=c++14
)

add_executable(decltype_for_complicated_lvalues decltype_for_complicated_lvalues.cpp)

add_library(item02 problem.cpp
                   decltype_auto_for_function_return_types_cpp14.cpp
                   decltype_auto_for_normal_auto_variables_cpp14.cpp
                   typical_cases.cpp
                   string_deque.cpp
                   return_statements_cpp14.cpp)
