# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zxl/C:CPP projects"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zxl/C:CPP projects/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/遍历字符数组.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/遍历字符数组.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/遍历字符数组.dir/flags.make

CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o: CMakeFiles/遍历字符数组.dir/flags.make
CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o: ../基础部分/遍历字符数组.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o   -c "/Users/zxl/C:CPP projects/基础部分/遍历字符数组.c"

CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/zxl/C:CPP projects/基础部分/遍历字符数组.c" > CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.i

CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/zxl/C:CPP projects/基础部分/遍历字符数组.c" -o CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.s

# Object files for target 遍历字符数组
遍历字符数组_OBJECTS = \
"CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o"

# External object files for target 遍历字符数组
遍历字符数组_EXTERNAL_OBJECTS =

遍历字符数组: CMakeFiles/遍历字符数组.dir/基础部分/遍历字符数组.c.o
遍历字符数组: CMakeFiles/遍历字符数组.dir/build.make
遍历字符数组: CMakeFiles/遍历字符数组.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 遍历字符数组"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/遍历字符数组.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/遍历字符数组.dir/build: 遍历字符数组

.PHONY : CMakeFiles/遍历字符数组.dir/build

CMakeFiles/遍历字符数组.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/遍历字符数组.dir/cmake_clean.cmake
.PHONY : CMakeFiles/遍历字符数组.dir/clean

CMakeFiles/遍历字符数组.dir/depend:
	cd "/Users/zxl/C:CPP projects/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zxl/C:CPP projects" "/Users/zxl/C:CPP projects" "/Users/zxl/C:CPP projects/cmake-build-debug" "/Users/zxl/C:CPP projects/cmake-build-debug" "/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles/遍历字符数组.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/遍历字符数组.dir/depend

