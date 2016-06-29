set_source_files_properties(
    pinch_of_pseudocode.cpp
    case1_const.cpp
    case1_non_const.cpp
    case1_pointer.cpp
    case2_uref.cpp
    case3_pass_by_value.cpp
    array-to-pointer_decay_rule.cpp
    arrays_by_value.cpp
    arrays_by_reference.cpp
    function-to-pointer_decay_rule.cpp
    deduce_nb_array_elements.cpp
    array_and_pointer_parameter_equivalence.cpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(pinch_of_pseudocode pinch_of_pseudocode.cpp)
add_executable(case1_const case1_const.cpp)
add_executable(case1_non_const case1_non_const.cpp)
add_executable(case1_pointer case1_pointer.cpp)
add_executable(case2_uref case2_uref.cpp)
add_executable(case3_pass_by_value case3_pass_by_value.cpp)
add_executable(array-to-pointer_decay_rule array-to-pointer_decay_rule.cpp)
add_executable(arrays_by_value arrays_by_value.cpp)
add_executable(arrays_by_reference arrays_by_reference.cpp)
add_executable(function-to-pointer_decay_rule function-to-pointer_decay_rule.cpp)

add_library(item01 deduce_nb_array_elements.cpp
                   array_and_pointer_parameter_equivalence.cpp)
