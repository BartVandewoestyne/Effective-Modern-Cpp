add_executable(alarm_with_lambda_cpp11 alarm_with_lambda_cpp11.cpp)

set_source_files_properties(alarm_with_lambda_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(alarm_with_lambda_cpp14 alarm_with_lambda_cpp14.cpp)

set_source_files_properties(alarm_with_lambda_and_overload_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(alarm_with_lambda_and_overload_cpp14 alarm_with_lambda_and_overload_cpp14.cpp)

add_executable(alarm_with_std_bind_incorrect alarm_with_std_bind_incorrect.cpp)

add_executable(alarm_with_std_bind_cpp11 alarm_with_std_bind_cpp11.cpp)

set_source_files_properties(alarm_with_std_bind_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(alarm_with_std_bind_cpp14 alarm_with_std_bind_cpp14.cpp)

set_source_files_properties(alarm_with_std_bind_and_overload_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(alarm_with_std_bind_and_overload_cpp14 alarm_with_std_bind_and_overload_cpp14.cpp)

add_executable(between_with_lambda_cpp11 between_with_lambda_cpp11.cpp)

set_source_files_properties(between_with_lambda_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(between_with_lambda_cpp14 between_with_lambda_cpp14.cpp)

add_executable(between_with_std_bind_cpp11 between_with_std_bind_cpp11.cpp)

set_source_files_properties(between_with_std_bind_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(between_with_std_bind_cpp14 between_with_std_bind_cpp14.cpp)

add_executable(compress_with_lambda compress_with_lambda.cpp)

add_executable(compress_with_std_bind compress_with_std_bind.cpp)


set_source_files_properties(polymorphic_function_objects_with_lambda_cpp14.cpp PROPERTIES COMPILE_FLAGS "-std=c++14 -stdlib=libc++")
add_executable(polymorphic_function_objects_with_lambda_cpp14 polymorphic_function_objects_with_lambda_cpp14.cpp)

add_executable(polymorphic_function_objects_with_std_bind polymorphic_function_objects_with_std_bind.cpp)
