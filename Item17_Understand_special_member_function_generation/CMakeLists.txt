SET(SRC_FILES_Cxx11
    Widget01.cpp
    Widget02.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")

add_library(itemXX Widget01.cpp
                   Widget02.cpp
                   Widget03.cpp
                   StringTable01.cpp
                   StringTable02.cpp)
