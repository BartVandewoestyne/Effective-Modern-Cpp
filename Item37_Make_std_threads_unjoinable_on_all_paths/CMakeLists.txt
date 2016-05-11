SET(SAMPLES_NAMES
    example1
    example2
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11;USE_PTHREAD")
