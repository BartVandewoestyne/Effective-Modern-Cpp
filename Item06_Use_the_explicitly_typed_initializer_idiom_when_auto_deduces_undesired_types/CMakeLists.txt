# ps: exception in execution !
# TODO: debug this sample !
SET(NAME_SAMPLES
    invisible_proxy_types
    typed_initializer_idiom
)
subitems_add_executables("${NAMES_SAMPLES}" "ADD_FLAG_FOR_CXX_11")

#subitem_add_executable(
#  NAME matrix_example
#  SRC matrix_example.cpp
#  ADD_FLAG_FOR_CXX_11
#)
