macro(add_flags SRC_FILES FLAGS)
#  MESSAGE("Flags list to add: ${FLAGS}")
#  MESSAGE("to this sources files:")
  foreach(src ${SRC_FILES})
#    MESSAGE("-> ${src}")
    set_source_files_properties(${src} PROPERTIES COMPILE_FLAGS ${FLAGS})
  endforeach()
endmacro()

macro(add_std_cxx14_flag SRC_FILES)
  add_flags("${SRC_FILES}" "-std=c++14")
endmacro()

macro(add_std_cxx11_flag SRC_FILES)
  add_flags("${SRC_FILES}" "-std=c++11")
endmacro()

function(SUBITEM_ADD)
  # url: https://cmake.org/cmake/help/v3.0/module/CMakeParseArguments.html
  set(options
      IS_EXECUTABLE
      IS_LIBRARY
      USE_BOOST
      USE_PTHREAD
      ADD_FLAG_FOR_CXX_11
      ADD_FLAG_FOR_CXX_14
      PRINT_DEBUG)
  set(oneValueArgs NAME)
  set(multiValueArgs SRC)
  cmake_parse_arguments(SUBITEM_ADD "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  ########################################################

  IF(${SUBITEM_ADD_ADD_FLAG_FOR_CXX_11} MATCHES "TRUE")
    add_std_cxx11_flag("${SUBITEM_ADD_SRC}")
  ENDIF()

  IF(${SUBITEM_ADD_ADD_FLAG_FOR_CXX_14} MATCHES "TRUE")
    add_std_cxx14_flag("${SUBITEM_ADD_SRC}")
  ENDIF()

  ########################################################

  IF(${SUBITEM_ADD_IS_EXECUTABLE} MATCHES "TRUE")
    add_executable(${SUBITEM_ADD_NAME} ${SUBITEM_ADD_SRC})
  ENDIF()

  IF(${SUBITEM_ADD_IS_LIBRARY} MATCHES "TRUE")
    add_library(${SUBITEM_ADD_NAME} ${SUBITEM_ADD_SRC})
  ENDIF()

  ########################################################

  IF(${SUBITEM_ADD_USE_BOOST} MATCHES "TRUE")
    target_link_libraries(${SUBITEM_ADD_NAME} ${Boost_LIBRARIES})
  ENDIF()

  IF(${SUBITEM_ADD_USE_PTHREAD} MATCHES "TRUE")
    target_link_libraries( ${SUBITEM_ADD_NAME} ${CMAKE_THREAD_LIBS_INIT})
  ENDIF()

  ########################################################

  IF(${SUBITEM_ADD_PRINT_DEBUG} MATCHES "TRUE")
    foreach(option ${options})
      MESSAGE("- ${option} = ${SUBITEM_ADD_${option}}")
    endforeach()
    MESSAGE("* SUBITEM_ADD_NAME = ${SUBITEM_ADD_NAME}")
    MESSAGE("# SUBITEM_ADD_SRC = ${SUBITEM_ADD_SRC}")
    #
#    #ps: problem with foreach => cause exception !
#    foreach(option ${oneValueArgs})
#      MESSAGE("- ${option} = ${SUBITEM_ADD_${option}}")
#    foreach(option ${multiValueArgs})
#      MESSAGE("- ${option} = ${SUBITEM_ADD_${option}}")
#    endforeach()

    MESSAGE("? IS_EXECUTABLE = ${SUBITEM_ADD_IS_EXECUTABLE}")
    MESSAGE("? IS_LIBRARY = ${SUBITEM_ADD_IS_LIBRARY}")
  ENDIF()

endfunction()

function(SUBITEM_ADD_EXECUTABLE)
  subitem_add(IS_EXECUTABLE ${ARGN})
endfunction(SUBITEM_ADD_EXECUTABLE)

function(SUBITEM_ADD_LIBRARY)
  subitem_add(IS_LIBRARY ${ARGN})
endfunction(SUBITEM_ADD_LIBRARY)

function(SUBITEMS_ADD_EXECUTABLES NAMES_SAMPLES FLAGS_FOR_SAMPLES)
  foreach(name_sample ${NAMES_SAMPLES})
    subitem_add_executable(
      NAME ${name_sample}
      SRC ${name_sample}.cpp
      ${FLAGS_FOR_SAMPLES}
    )
  endforeach()
endfunction()

function(SUBITEMS_ADD_LIBRARIES NAMES_SAMPLES FLAGS_FOR_SAMPLES)
  foreach(name_sample ${NAMES_SAMPLES})
    subitem_add_library(
      NAME ${name_sample}
      SRC ${name_sample}.cpp
      ${FLAGS_FOR_SAMPLES}
    )
  endforeach()
endfunction()

