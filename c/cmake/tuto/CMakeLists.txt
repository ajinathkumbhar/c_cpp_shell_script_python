#cmake_mininum_required (VERSION 2.6)
    cmake_minimum_required (VERSION 2.6)
    project (Tutorial)

# The Version number 
    set (Tutorial_VERSION_MAJOR 1)
    set (Tutorial_VERSION_MINOR 3)

# configure a header file to pass some of the cmake settings
# to the source code
    configure_file (
            "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
            "${PROJECT_BINARY_DIR}/TutorialConfig.h"
            )
# add the binary tree to the search path for include files
# so that we will find TutorialCofig.h
    include_directories("${PROJECT_BINARY_DIR}")

# add the executable
    add_executable(Tutorial tutorial.cxx)


