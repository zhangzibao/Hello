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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\C++\Hello

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\C++\Hello\cmake-build-debug

# Utility rule file for PROJECT_NAME_autogen.

# Include the progress variables for this target.
include CMakeFiles/PROJECT_NAME_autogen.dir/progress.make

CMakeFiles/PROJECT_NAME_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=G:\C++\Hello\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target PROJECT_NAME"
	"C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E cmake_autogen G:/C++/Hello/cmake-build-debug/CMakeFiles/PROJECT_NAME_autogen.dir/AutogenInfo.cmake Debug

PROJECT_NAME_autogen: CMakeFiles/PROJECT_NAME_autogen
PROJECT_NAME_autogen: CMakeFiles/PROJECT_NAME_autogen.dir/build.make

.PHONY : PROJECT_NAME_autogen

# Rule to build all files generated by this target.
CMakeFiles/PROJECT_NAME_autogen.dir/build: PROJECT_NAME_autogen

.PHONY : CMakeFiles/PROJECT_NAME_autogen.dir/build

CMakeFiles/PROJECT_NAME_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PROJECT_NAME_autogen.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PROJECT_NAME_autogen.dir/clean

CMakeFiles/PROJECT_NAME_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\C++\Hello G:\C++\Hello G:\C++\Hello\cmake-build-debug G:\C++\Hello\cmake-build-debug G:\C++\Hello\cmake-build-debug\CMakeFiles\PROJECT_NAME_autogen.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PROJECT_NAME_autogen.dir/depend

