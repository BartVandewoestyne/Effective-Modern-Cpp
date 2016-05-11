SET(NAMES_SAMPLES
    default_launch_policy
    guaranteeing_truly_asynchronous_execution
    interesting_implications
    really_async_cpp11
    thread_local_storage
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11;USE_PTHREAD")

SET(NAMES_SAMPLES
    really_async_cpp14
    wait-based_loops
    wait-based_loops_fixed
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_14;USE_PTHREAD")
# url: http://stackoverflow.com/questions/35856969/chrono-literals-is-not-a-namespace-name
