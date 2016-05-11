SET(NAMES_SAMPLES
    pointer_overload
    code_clarity
    template_example_flat
    template_example_templatized
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

subitems_add_executables("template_example_templatized_cpp14" "ADD_FLAG_FOR_CXX_14")
