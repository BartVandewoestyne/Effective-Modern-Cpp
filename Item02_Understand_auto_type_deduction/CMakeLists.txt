SET(SAMPLES_NAMES
    auto_type_deduction
    auto_deduction_vs_template_deduction
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11")

subitems_add_executables("function_return_type_deduction" "ADD_FLAG_FOR_CXX_14")
