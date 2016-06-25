set_source_files_properties(unscoped_enums_useful04_cpp14.cpp PROPERTIES COMPILE_FLAGS -std=c++14)

add_library(item10 unscoped_enums.cpp
                   scoped_enums.cpp
                   semantic_travesties01.cpp
                   semantic_travesties02.cpp
                   semantic_travesties03.cpp
                   forward_declaring.cpp
                   forward_declared_enums.cpp
                   underlying_type01.cpp
                   underlying_type02.cpp
                   unscoped_enums_useful01.cpp
                   unscoped_enums_useful02.cpp
                   unscoped_enums_useful03.cpp
                   unscoped_enums_useful04.cpp
                   unscoped_enums_useful04_cpp14.cpp)
