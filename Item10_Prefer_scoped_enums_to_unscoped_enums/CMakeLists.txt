SET(SRC_FILES
    scoped_enums.cpp
    semantic_travesties01.cpp
    semantic_travesties02.cpp
    semantic_travesties03.cpp
    forward_declaring.cpp
    forward_declared_enums.cpp
    underlying_type02.cpp
    unscoped_enums_useful01.cpp
    unscoped_enums_useful02.cpp
    unscoped_enums_useful03.cpp
    unscoped_enums_useful04.cpp
)
subitem_add_library(NAME item10 SRC ${SRC_FILES} ADD_FLAG_FOR_CXX_11)

# TODO: compile C++14 code  unscoped_enums_useful04_cpp14.cpp)
