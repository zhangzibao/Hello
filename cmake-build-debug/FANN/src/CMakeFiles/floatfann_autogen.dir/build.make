# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "A:\Jetbrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "A:\Jetbrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\C++\Hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\C++\Hello\cmake-build-debug

# Utility rule file for floatfann_autogen.

# Include the progress variables for this target.
include FANN/src/CMakeFiles/floatfann_autogen.dir/progress.make

FANN/src/CMakeFiles/floatfann_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=G:\C++\Hello\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target floatfann"
	cd /d G:\C++\Hello\cmake-build-debug\FANN\src && "A:\Jetbrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E cmake_autogen G:/C++/Hello/cmake-build-debug/FANN/src/CMakeFiles/floatfann_autogen.dir/AutogenInfo.cmake Debug

floatfann_autogen: FANN/src/CMakeFiles/floatfann_autogen
floatfann_autogen: FANN/src/CMakeFiles/floatfann_autogen.dir/build.make

.PHONY : floatfann_autogen

# Rule to build all files generated by this target.
FANN/src/CMakeFiles/floatfann_autogen.dir/build: floatfann_autogen

.PHONY : FANN/src/CMakeFiles/floatfann_autogen.dir/build

FANN/src/CMakeFiles/floatfann_autogen.dir/clean:
	cd /d G:\C++\Hello\cmake-build-debug\FANN\src && $(CMAKE_COMMAND) -P CMakeFiles\floatfann_autogen.dir\cmake_clean.cmake
.PHONY : FANN/src/CMakeFiles/floatfann_autogen.dir/clean

FANN/src/CMakeFiles/floatfann_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\C++\Hello G:\C++\Hello\FANN\src G:\C++\Hello\cmake-build-debug G:\C++\Hello\cmake-build-debug\FANN\src G:\C++\Hello\cmake-build-debug\FANN\src\CMakeFiles\floatfann_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : FANN/src/CMakeFiles/floatfann_autogen.dir/depend

