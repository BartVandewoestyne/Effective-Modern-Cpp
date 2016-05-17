SET(SRC_FILES_Cxx14
    by_reference_capture.cpp
    Widget.cpp
)
add_std_cxx14_flag("${SRC_FILES_Cxx14}")
add_executable(by_reference_capture ${SRC_FILES_Cxx14})
