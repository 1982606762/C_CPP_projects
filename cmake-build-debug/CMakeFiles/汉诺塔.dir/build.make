# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "/Users/zxl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/zxl/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/213.6777.58/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/zxl/study/C:CPP projects"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/zxl/study/C:CPP projects/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/汉诺塔.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/汉诺塔.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/汉诺塔.dir/flags.make

CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o: CMakeFiles/汉诺塔.dir/flags.make
CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o: ../杂/汉诺塔.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/zxl/study/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o -c "/Users/zxl/study/C:CPP projects/杂/汉诺塔.cpp"

CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/zxl/study/C:CPP projects/杂/汉诺塔.cpp" > CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.i

CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/zxl/study/C:CPP projects/杂/汉诺塔.cpp" -o CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.s

# Object files for target 汉诺塔
汉诺塔_OBJECTS = \
"CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o"

# External object files for target 汉诺塔
汉诺塔_EXTERNAL_OBJECTS =

汉诺塔: CMakeFiles/汉诺塔.dir/杂/汉诺塔.cpp.o
汉诺塔: CMakeFiles/汉诺塔.dir/build.make
汉诺塔: CMakeFiles/汉诺塔.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/zxl/study/C:CPP projects/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 汉诺塔"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/汉诺塔.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/汉诺塔.dir/build: 汉诺塔
.PHONY : CMakeFiles/汉诺塔.dir/build

CMakeFiles/汉诺塔.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/汉诺塔.dir/cmake_clean.cmake
.PHONY : CMakeFiles/汉诺塔.dir/clean

CMakeFiles/汉诺塔.dir/depend:
	cd "/Users/zxl/study/C:CPP projects/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/zxl/study/C:CPP projects" "/Users/zxl/study/C:CPP projects" "/Users/zxl/study/C:CPP projects/cmake-build-debug" "/Users/zxl/study/C:CPP projects/cmake-build-debug" "/Users/zxl/study/C:CPP projects/cmake-build-debug/CMakeFiles/汉诺塔.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/汉诺塔.dir/depend

