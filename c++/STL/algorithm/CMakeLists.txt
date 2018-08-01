cmake_minimum_required (VERSION 2.6)
project (sorting)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#include_directories ("$(PROJECT_BINARY_DIR)")
include_directories ("$(PROJECT_BINARY_DIR)/libstldata")
add_subdirectory (libstldata)
add_executable (sorting src/STL_sorting.cpp)
target_link_libraries (sorting stldata)
