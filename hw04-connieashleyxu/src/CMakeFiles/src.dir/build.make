# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/disk.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/disk.cpp.o: src/disk.cpp
src/CMakeFiles/src.dir/disk.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/disk.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/disk.cpp.o -MF CMakeFiles/src.dir/disk.cpp.o.d -o CMakeFiles/src.dir/disk.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/disk.cpp

src/CMakeFiles/src.dir/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/disk.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/disk.cpp > CMakeFiles/src.dir/disk.cpp.i

src/CMakeFiles/src.dir/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/disk.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/disk.cpp -o CMakeFiles/src.dir/disk.cpp.s

src/CMakeFiles/src.dir/peg.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/peg.cpp.o: src/peg.cpp
src/CMakeFiles/src.dir/peg.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/peg.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/peg.cpp.o -MF CMakeFiles/src.dir/peg.cpp.o.d -o CMakeFiles/src.dir/peg.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/peg.cpp

src/CMakeFiles/src.dir/peg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/peg.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/peg.cpp > CMakeFiles/src.dir/peg.cpp.i

src/CMakeFiles/src.dir/peg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/peg.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/peg.cpp -o CMakeFiles/src.dir/peg.cpp.s

src/CMakeFiles/src.dir/towers.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/towers.cpp.o: src/towers.cpp
src/CMakeFiles/src.dir/towers.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/towers.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/towers.cpp.o -MF CMakeFiles/src.dir/towers.cpp.o.d -o CMakeFiles/src.dir/towers.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/towers.cpp

src/CMakeFiles/src.dir/towers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/towers.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/towers.cpp > CMakeFiles/src.dir/towers.cpp.i

src/CMakeFiles/src.dir/towers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/towers.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/towers.cpp -o CMakeFiles/src.dir/towers.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/disk.cpp.o" \
"CMakeFiles/src.dir/peg.cpp.o" \
"CMakeFiles/src.dir/towers.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/disk.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/peg.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/towers.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsrc.a"
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw04-connieashleyxu/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

