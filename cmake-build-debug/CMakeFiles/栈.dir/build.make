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
include CMakeFiles/栈.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/栈.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/栈.dir/flags.make

CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o: CMakeFiles/栈.dir/flags.make
CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o: ../基础部分/C督学营第三周/栈.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o -c "/Users/zxl/学习文件夹/C:CPP projects/基础部分/C督学营第三周/栈.c"

CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/zxl/学习文件夹/C:CPP projects/基础部分/C督学营第三周/栈.c" > CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.i

CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/zxl/学习文件夹/C:CPP projects/基础部分/C督学营第三周/栈.c" -o CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.s

# Object files for target 栈
栈_OBJECTS = \
"CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o"

# External object files for target 栈
栈_EXTERNAL_OBJECTS =

栈: CMakeFiles/栈.dir/基础部分/C督学营第三周/栈.o
栈: CMakeFiles/栈.dir/build.make
栈: CMakeFiles/栈.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 栈"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/栈.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/栈.dir/build: 栈

.PHONY : CMakeFiles/栈.dir/build

CMakeFiles/栈.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/栈.dir/cmake_clean.cmake
.PHONY : CMakeFiles/栈.dir/clean

CMakeFiles/栈.dir/depend:
	cd "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zxl/学习文件夹/C:CPP projects" "/Users/zxl/学习文件夹/C:CPP projects" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug" "/Users/zxl/学习文件夹/C:CPP projects/cmake-build-debug/CMakeFiles/栈.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/栈.dir/depend

