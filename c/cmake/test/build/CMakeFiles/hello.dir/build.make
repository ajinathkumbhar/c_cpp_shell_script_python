# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ajinath/0002-work/00_Me/C++/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ajinath/0002-work/00_Me/C++/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/test.cpp.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/test.cpp.o: ../test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ajinath/0002-work/00_Me/C++/cmake/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hello.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hello.dir/test.cpp.o -c /home/ajinath/0002-work/00_Me/C++/cmake/test.cpp

CMakeFiles/hello.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ajinath/0002-work/00_Me/C++/cmake/test.cpp > CMakeFiles/hello.dir/test.cpp.i

CMakeFiles/hello.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ajinath/0002-work/00_Me/C++/cmake/test.cpp -o CMakeFiles/hello.dir/test.cpp.s

CMakeFiles/hello.dir/test.cpp.o.requires:
.PHONY : CMakeFiles/hello.dir/test.cpp.o.requires

CMakeFiles/hello.dir/test.cpp.o.provides: CMakeFiles/hello.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/hello.dir/build.make CMakeFiles/hello.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/hello.dir/test.cpp.o.provides

CMakeFiles/hello.dir/test.cpp.o.provides.build: CMakeFiles/hello.dir/test.cpp.o

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/test.cpp.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

../bin/hello: CMakeFiles/hello.dir/test.cpp.o
../bin/hello: CMakeFiles/hello.dir/build.make
../bin/hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../bin/hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: ../bin/hello
.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/requires: CMakeFiles/hello.dir/test.cpp.o.requires
.PHONY : CMakeFiles/hello.dir/requires

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/ajinath/0002-work/00_Me/C++/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ajinath/0002-work/00_Me/C++/cmake /home/ajinath/0002-work/00_Me/C++/cmake /home/ajinath/0002-work/00_Me/C++/cmake/build /home/ajinath/0002-work/00_Me/C++/cmake/build /home/ajinath/0002-work/00_Me/C++/cmake/build/CMakeFiles/hello.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello.dir/depend

