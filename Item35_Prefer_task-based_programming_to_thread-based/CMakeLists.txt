SET(SAMPLES_NAMES
    software_threads
    task_based_approach
    thread_based_approach
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11;USE_PTHREAD")
