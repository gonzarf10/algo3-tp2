# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/gtest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/gtest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gtest.dir/flags.make

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj: CMakeFiles/gtest.dir/flags.make
CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj: C:/Users/gonza/OneDrive/Documentos/code/algo3-tp2/ejercicio1/tests/gtest-1.8.1/gtest-all.cc
CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj: CMakeFiles/gtest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj -MF CMakeFiles\gtest.dir\tests\gtest-1.8.1\gtest-all.cc.obj.d -o CMakeFiles\gtest.dir\tests\gtest-1.8.1\gtest-all.cc.obj -c C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\tests\gtest-1.8.1\gtest-all.cc

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\tests\gtest-1.8.1\gtest-all.cc > CMakeFiles\gtest.dir\tests\gtest-1.8.1\gtest-all.cc.i

CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\tests\gtest-1.8.1\gtest-all.cc -o CMakeFiles\gtest.dir\tests\gtest-1.8.1\gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

libgtest.a: CMakeFiles/gtest.dir/tests/gtest-1.8.1/gtest-all.cc.obj
libgtest.a: CMakeFiles/gtest.dir/build.make
libgtest.a: CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest.a"
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gtest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gtest.dir/build: libgtest.a
.PHONY : CMakeFiles/gtest.dir/build

CMakeFiles/gtest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\gtest.dir\cmake_clean.cmake
.PHONY : CMakeFiles/gtest.dir/clean

CMakeFiles/gtest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1 C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1 C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug C:\Users\gonza\OneDrive\Documentos\code\algo3-tp2\ejercicio1\cmake-build-debug\CMakeFiles\gtest.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gtest.dir/depend

