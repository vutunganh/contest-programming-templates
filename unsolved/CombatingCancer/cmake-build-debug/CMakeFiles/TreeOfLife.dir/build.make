# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/local/jetbrains/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/jetbrains/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TreeOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TreeOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TreeOfLife.dir/flags.make

CMakeFiles/TreeOfLife.dir/main.cpp.o: CMakeFiles/TreeOfLife.dir/flags.make
CMakeFiles/TreeOfLife.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TreeOfLife.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TreeOfLife.dir/main.cpp.o -c /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/main.cpp

CMakeFiles/TreeOfLife.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TreeOfLife.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/main.cpp > CMakeFiles/TreeOfLife.dir/main.cpp.i

CMakeFiles/TreeOfLife.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TreeOfLife.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/main.cpp -o CMakeFiles/TreeOfLife.dir/main.cpp.s

CMakeFiles/TreeOfLife.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/TreeOfLife.dir/main.cpp.o.requires

CMakeFiles/TreeOfLife.dir/main.cpp.o.provides: CMakeFiles/TreeOfLife.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TreeOfLife.dir/build.make CMakeFiles/TreeOfLife.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/TreeOfLife.dir/main.cpp.o.provides

CMakeFiles/TreeOfLife.dir/main.cpp.o.provides.build: CMakeFiles/TreeOfLife.dir/main.cpp.o


# Object files for target TreeOfLife
TreeOfLife_OBJECTS = \
"CMakeFiles/TreeOfLife.dir/main.cpp.o"

# External object files for target TreeOfLife
TreeOfLife_EXTERNAL_OBJECTS =

TreeOfLife: CMakeFiles/TreeOfLife.dir/main.cpp.o
TreeOfLife: CMakeFiles/TreeOfLife.dir/build.make
TreeOfLife: CMakeFiles/TreeOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TreeOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TreeOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TreeOfLife.dir/build: TreeOfLife

.PHONY : CMakeFiles/TreeOfLife.dir/build

CMakeFiles/TreeOfLife.dir/requires: CMakeFiles/TreeOfLife.dir/main.cpp.o.requires

.PHONY : CMakeFiles/TreeOfLife.dir/requires

CMakeFiles/TreeOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TreeOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TreeOfLife.dir/clean

CMakeFiles/TreeOfLife.dir/depend:
	cd /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug /home/users/k/kristja6/ACM/my-z-kacerova/unsolved/CombatingCancer/cmake-build-debug/CMakeFiles/TreeOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TreeOfLife.dir/depend

