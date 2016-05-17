SET(SAMPLES_NAMES
    braced_initializers
    null_pointers
    declaration-only_integral_static_const_data_members
    overloaded_function_names_and_template_names
    bitfields
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11")
