SET(SAMPLES_NAMES
    move_capture1_cpp11
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11")

SET(SAMPLES_NAMES
    init_capture_cpp14
    init_capture_cpp11
    move_capture1_cpp14
    move_capture2
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_14")
