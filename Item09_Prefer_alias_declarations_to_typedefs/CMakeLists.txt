SET(SRC_FILES
    function_pointers.cpp
    linked_list_synonym_with_alias_template01.cpp
    linked_list_synonym_with_alias_template02.cpp
    linked_list_synonym_with_typedef01.cpp
    linked_list_synonym_with_typedef02.cpp
    # TODO wine.cpp
)
subitem_add_library(NAME item09 SRC ${SRC_FILES} ADD_FLAG_FOR_CXX_11)
