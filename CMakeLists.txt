cmake_minimum_required(VERSION 2.6)

# Note: the 'C' seems necessary for CMake 3.2.2 but might not be necessary with
# later versions of CMake.
project(Effective_Modern_C++ C CXX)

# Only from gcc 4.9 and cland 3.5 are the options -std=c++11 and -std=c++14 available.
# See:
#   https://gcc.gnu.org/projects/cxx-status.html
#   http://clang.llvm.org/cxx_status.html
# Since CMAKE_CXX_COMPILER_VERSION is only available from CMake 2.8.10 on, we currently comment
# this check out.
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.9)
#        message(FATAL_ERROR "GCC version must be at least 4.9!")
#    endif()
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
#        message(FATAL_ERROR "Clang version must be at least 3.5!")
#    endif()
#else()
#    message(WARNING "You are using an unsupported compiler!  Compilation has only been tested with Clang and GCC.")
#endif()

set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(Threads REQUIRED)

add_subdirectory(Item01_Understand_template_type_deduction)
add_subdirectory(Item02_Understand_auto_type_deduction)
add_subdirectory(Item03_Understand_decltype)
add_subdirectory(Item04_Know_how_to_view_deduced_types)
add_subdirectory(Item05_Prefer_auto_to_explicit_type_declarations)
add_subdirectory(Item06_Use_the_explicitly_typed_initializer_idiom_when_auto_deduces_undesired_types)
add_subdirectory("Item07_Distinguish_between()_and_{}_when_creating_objects")
add_subdirectory(Item09_Prefer_alias_declarations_to_typedefs)
add_subdirectory(Item08_Prefer_nullptr_to_0_and_NULL)
add_subdirectory(Item10_Prefer_scoped_enums_to_unscoped_enums)
add_subdirectory(Item11_Prefer_deleted_functions_to_private_undefined_ones)
add_subdirectory(Item12_Declare_overriding_functions_override)
# TODO: comment this out when clang supports it: add_subdirectory(Item13_Prefer_const_iterators_to_iterators)
add_subdirectory(Item14_Declare_functions_noexcept_if_they_wont_emit_exceptions)
add_subdirectory(Item15_Use_constexpr_whenever_possible)
add_subdirectory(Item16_Make_const_member_functions_thread-safe)
add_subdirectory(Item17_Understand_special_member_function_generation)
add_subdirectory(Item18_Use_std_unique_ptr_for_exclusive-ownership_resource_management)
add_subdirectory(Item19_Use_std_shared_ptr_for_shared-ownership_resource_management)
add_subdirectory(Item20_Use_std_weak_ptr_for_std_shared_ptr-like_pointers_that_can_dangle)
add_subdirectory(Item21_Prefer_std_make_unique_and_std_make_shared_to_direct_use_of_new)
add_subdirectory(Item22_When_using_the_Pimpl_Idiom_define_special_member_functions_in_the_implementation_file)
add_subdirectory(Item23_Understand_std_move_and_std_forward)
add_subdirectory(Item24_Distinguish_universal_references_from_rvalue_references)
add_subdirectory(Item25_Use_std_move_on_rvalue_references_std_forward_on_universal_references)
add_subdirectory(Item26_Avoid_overloading_on_universal_references)
add_subdirectory(Item27_Familiarize_yourself_with_alternatives_to_overloading_on_universal_references)
add_subdirectory(Item28_Understand_reference_collapsing)
add_subdirectory(Item29_Assume_that_move_operations_are_not_present_not_cheap_and_not_used)
add_subdirectory(Item30_Familiarize_yourself_with_perfect_forwarding_failure_cases)
add_subdirectory(Item31_Avoid_default_capture_modes)
add_subdirectory(Item32_Use_init_capture_to_move_objects_into_closures)
add_subdirectory(Item33_Use_decltype_on_autorr_parameters_to_std_forward_them)
#add_subdirectory(Item34_Prefer_lambdas_to_std_bind)
add_subdirectory(Item35_Prefer_task-based_programming_to_thread-based)
add_subdirectory(Item36_Specify_std_launch_async_if_asynchronicity_is_essential)
add_subdirectory(Item37_Make_std_threads_unjoinable_on_all_paths)
add_subdirectory(Item38_Be_aware_of_varying_thread_handle_destructor_behavior)
