add_executable(overriding_explained overriding_explained.cpp)

SET(NAMES_SAMPLES
    reference-qualified_member_functions_use_case_problem_demonstration
    reference-qualified_member_functions_use_case_problem_solution
    reference_qualifiers_example
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

SET(NAMES_SAMPLES
    typical_errors
    typical_errors_with_override_added
    typical_errors_corrected
    override_games
)
subitems_add_libraries("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

add_library(override_legacy_code override_legacy_code.cpp)
