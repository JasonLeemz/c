# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\develop\study\c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\develop\study\c\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c.dir/flags.make

CMakeFiles/c.dir/main.cpp.obj: CMakeFiles/c.dir/flags.make
CMakeFiles/c.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\develop\study\c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c.dir/main.cpp.obj"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\c.dir\main.cpp.obj -c D:\develop\study\c\main.cpp

CMakeFiles/c.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c.dir/main.cpp.i"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\develop\study\c\main.cpp > CMakeFiles\c.dir\main.cpp.i

CMakeFiles/c.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c.dir/main.cpp.s"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\develop\study\c\main.cpp -o CMakeFiles\c.dir\main.cpp.s

CMakeFiles/c.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/c.dir/main.cpp.obj.requires

CMakeFiles/c.dir/main.cpp.obj.provides: CMakeFiles/c.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\c.dir\build.make CMakeFiles/c.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/c.dir/main.cpp.obj.provides

CMakeFiles/c.dir/main.cpp.obj.provides.build: CMakeFiles/c.dir/main.cpp.obj


CMakeFiles/c.dir/test.cpp.obj: CMakeFiles/c.dir/flags.make
CMakeFiles/c.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\develop\study\c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/c.dir/test.cpp.obj"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe"  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\c.dir\test.cpp.obj -c D:\develop\study\c\test.cpp

CMakeFiles/c.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c.dir/test.cpp.i"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\develop\study\c\test.cpp > CMakeFiles\c.dir\test.cpp.i

CMakeFiles/c.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c.dir/test.cpp.s"
	"E:\Program Files (x86)\CodeBlocks\MinGW\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\develop\study\c\test.cpp -o CMakeFiles\c.dir\test.cpp.s

CMakeFiles/c.dir/test.cpp.obj.requires:

.PHONY : CMakeFiles/c.dir/test.cpp.obj.requires

CMakeFiles/c.dir/test.cpp.obj.provides: CMakeFiles/c.dir/test.cpp.obj.requires
	$(MAKE) -f CMakeFiles\c.dir\build.make CMakeFiles/c.dir/test.cpp.obj.provides.build
.PHONY : CMakeFiles/c.dir/test.cpp.obj.provides

CMakeFiles/c.dir/test.cpp.obj.provides.build: CMakeFiles/c.dir/test.cpp.obj


# Object files for target c
c_OBJECTS = \
"CMakeFiles/c.dir/main.cpp.obj" \
"CMakeFiles/c.dir/test.cpp.obj"

# External object files for target c
c_EXTERNAL_OBJECTS =

c.exe: CMakeFiles/c.dir/main.cpp.obj
c.exe: CMakeFiles/c.dir/test.cpp.obj
c.exe: CMakeFiles/c.dir/build.make
c.exe: CMakeFiles/c.dir/linklibs.rsp
c.exe: CMakeFiles/c.dir/objects1.rsp
c.exe: CMakeFiles/c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\develop\study\c\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable c.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\c.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c.dir/build: c.exe

.PHONY : CMakeFiles/c.dir/build

CMakeFiles/c.dir/requires: CMakeFiles/c.dir/main.cpp.obj.requires
CMakeFiles/c.dir/requires: CMakeFiles/c.dir/test.cpp.obj.requires

.PHONY : CMakeFiles/c.dir/requires

CMakeFiles/c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\c.dir\cmake_clean.cmake
.PHONY : CMakeFiles/c.dir/clean

CMakeFiles/c.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\develop\study\c D:\develop\study\c D:\develop\study\c\cmake-build-debug D:\develop\study\c\cmake-build-debug D:\develop\study\c\cmake-build-debug\CMakeFiles\c.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c.dir/depend
