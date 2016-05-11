subitems_add_executables("Item12" "ADD_FLAG_FOR_CXX_11")

SET(NAMES_SAMPLES
    pointer_example
    Widget
)
subitems_add_libraries("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")
