SET(SAMPLES_NAMES
    Person
    logAndAdd_inefficient
    logAndAdd_with_uref
    logAndAdd_with_uref_overloaded
)
subitems_add_executables("${SAMPLES_NAMES}" "ADD_FLAG_FOR_CXX_11")
