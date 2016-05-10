add_executable(pointer_overload pointer_overload.cpp)
add_executable(code_clarity code_clarity.cpp)
add_executable(template_example_flat template_example_flat.cpp)

# TODO: compile this as C++11
add_executable(template_example_templatized template_example_templatized.cpp)

# TODO: compile this as C++14
set_source_files_properties(template_example_templatized_cpp14.cpp PROPERTIES COMPILE_FLAGS -std=c++14)
add_executable(template_example_templatized_cpp14 template_example_templatized_cpp14.cpp)
