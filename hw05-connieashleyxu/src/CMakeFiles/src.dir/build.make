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
CMAKE_SOURCE_DIR = /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/Cards.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Cards.cpp.o: src/Cards.cpp
src/CMakeFiles/src.dir/Cards.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/Cards.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Cards.cpp.o -MF CMakeFiles/src.dir/Cards.cpp.o.d -o CMakeFiles/src.dir/Cards.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Cards.cpp

src/CMakeFiles/src.dir/Cards.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Cards.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Cards.cpp > CMakeFiles/src.dir/Cards.cpp.i

src/CMakeFiles/src.dir/Cards.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Cards.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Cards.cpp -o CMakeFiles/src.dir/Cards.cpp.s

src/CMakeFiles/src.dir/Play.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/Play.cpp.o: src/Play.cpp
src/CMakeFiles/src.dir/Play.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/Play.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/Play.cpp.o -MF CMakeFiles/src.dir/Play.cpp.o.d -o CMakeFiles/src.dir/Play.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Play.cpp

src/CMakeFiles/src.dir/Play.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/Play.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Play.cpp > CMakeFiles/src.dir/Play.cpp.i

src/CMakeFiles/src.dir/Play.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/Play.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/Play.cpp -o CMakeFiles/src.dir/Play.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/Cards.cpp.o" \
"CMakeFiles/src.dir/Play.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/Cards.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/Play.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libsrc.a"
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw05-connieashleyxu/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

