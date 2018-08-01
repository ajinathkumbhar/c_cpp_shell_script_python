cmake_minimum_required (VERSION 2.6)
project (libstldata)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $(CMAKE_BINARY_DIR/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORU $(CMAKE_BINARY_DIR/bin)

include_directories("$(PROJECT_BINARY_DIR)")
add_library(libstldata src/STLdata.cpp)

add_executable(libstldata.so src/STLdata.cpp)
