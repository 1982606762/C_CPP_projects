# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zxl/学习文件夹/C:CPP projects"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Experiment2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Experiment2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Experiment2.dir/flags.make

CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o: CMakeFiles/Experiment2.dir/flags.make
CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o: ../编译原理/Experiment2/Experiment2/Experiment2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o -c "/Users/zxl/学习文件夹/C:CPP projects/编译原理/Experiment2/Experiment2/Experiment2.cpp"

CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zxl/学习文件夹/C:CPP projects/编译原理/Experiment2/Experiment2/Experiment2.cpp" > CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.i

CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zxl/学习文件夹/C:CPP projects/编译原理/Experiment2/Experiment2/Experiment2.cpp" -o CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.s

# Object files for target Experiment2
Experiment2_OBJECTS = \
"CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o"

# External object files for target Experiment2
Experiment2_EXTERNAL_OBJECTS =

Experiment2: CMakeFiles/Experiment2.dir/编译原理/Experiment2/Experiment2/Experiment2.o
Experiment2: CMakeFiles/Experiment2.dir/build.make
Experiment2: CMakeFiles/Experiment2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Experiment2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Experiment2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Experiment2.dir/build: Experiment2

.PHONY : CMakeFiles/Experiment2.dir/build

CMakeFiles/Experiment2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Experiment2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Experiment2.dir/clean

CMakeFiles/Experiment2.dir/depend:
	cd "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zxl/学习文件夹/C:CPP projects" "/Users/zxl/学习文件夹/C:CPP projects" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles/Experiment2.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Experiment2.dir/depend

