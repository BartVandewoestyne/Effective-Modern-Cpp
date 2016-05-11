SET(SRC_FILES_Cxx11
    alternative_pass_by_value.cpp
    tag_dispatch01.cpp
    tag_dispatch02.cpp
    constraining_templates01.cpp
    constraining_templates02_cpp11.cpp
)
add_std_cxx11_flag("${SRC_FILES_Cxx11}")

SET(SRC_FILES_Cxx14
    constraining_templates02_cpp14.cpp
    constraining_templates03_cpp14.cpp
    constraining_templates04_cpp14.cpp
)
add_std_cxx14_flag("${SRC_FILES_Cxx14}")

add_library(alternatives_to_uref_overloading alternative_pass_by_value.cpp
                                             tag_dispatch01.cpp
                                             tag_dispatch02.cpp
                                             constraining_templates01.cpp
                                             constraining_templates02_cpp11.cpp
                                             constraining_templates02_cpp14.cpp
                                             constraining_templates03_cpp14.cpp
                                             constraining_templates04_cpp14.cpp)
