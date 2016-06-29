set_source_files_properties(
    auto_type_deduction.cpp
    auto_deduction_vs_template_deduction.cpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)
set_source_files_properties(
    function_return_type_deduction.cpp
    PROPERTIES COMPILE_FLAGS -std=c++14
)

add_executable(auto_type_deduction auto_type_deduction.cpp)
add_executable(auto_deduction_vs_template_deduction auto_deduction_vs_template_deduction.cpp)
add_executable(function_return_type_deduction function_return_type_deduction.cpp)
