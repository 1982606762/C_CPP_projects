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
include CMakeFiles/宏定义.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/宏定义.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/宏定义.dir/flags.make

CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o: CMakeFiles/宏定义.dir/flags.make
CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o: ../基础部分/思考题/宏定义函数.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o   -c "/Users/zxl/C:CPP projects/基础部分/思考题/宏定义函数.c"

CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/zxl/C:CPP projects/基础部分/思考题/宏定义函数.c" > CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.i

CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/zxl/C:CPP projects/基础部分/思考题/宏定义函数.c" -o CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.s

# Object files for target 宏定义
宏定义_OBJECTS = \
"CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o"

# External object files for target 宏定义
宏定义_EXTERNAL_OBJECTS =

宏定义: CMakeFiles/宏定义.dir/基础部分/思考题/宏定义函数.o
宏定义: CMakeFiles/宏定义.dir/build.make
宏定义: CMakeFiles/宏定义.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 宏定义"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/宏定义.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/宏定义.dir/build: 宏定义

.PHONY : CMakeFiles/宏定义.dir/build

CMakeFiles/宏定义.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/宏定义.dir/cmake_clean.cmake
.PHONY : CMakeFiles/宏定义.dir/clean

CMakeFiles/宏定义.dir/depend:
	cd "/Users/zxl/C:CPP projects/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zxl/C:CPP projects" "/Users/zxl/C:CPP projects" "/Users/zxl/C:CPP projects/cmake-build-debug" "/Users/zxl/C:CPP projects/cmake-build-debug" "/Users/zxl/C:CPP projects/cmake-build-debug/CMakeFiles/宏定义.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/宏定义.dir/depend

