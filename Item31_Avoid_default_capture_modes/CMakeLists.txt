set_source_files_properties(by_reference_capture.cpp PROPERTIES COMPILE_FLAGS "-std=c++14")

add_executable(by_reference_capture
               Widget.cpp utils.cpp by_reference_capture.cpp)
