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
CMAKE_SOURCE_DIR = /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/money.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/money.cpp.o: src/money.cpp
src/CMakeFiles/src.dir/money.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/money.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/money.cpp.o -MF CMakeFiles/src.dir/money.cpp.o.d -o CMakeFiles/src.dir/money.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/money.cpp

src/CMakeFiles/src.dir/money.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/money.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/money.cpp > CMakeFiles/src.dir/money.cpp.i

src/CMakeFiles/src.dir/money.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/money.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/money.cpp -o CMakeFiles/src.dir/money.cpp.s

src/CMakeFiles/src.dir/stock.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/stock.cpp.o: src/stock.cpp
src/CMakeFiles/src.dir/stock.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/stock.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/stock.cpp.o -MF CMakeFiles/src.dir/stock.cpp.o.d -o CMakeFiles/src.dir/stock.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/stock.cpp

src/CMakeFiles/src.dir/stock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/stock.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/stock.cpp > CMakeFiles/src.dir/stock.cpp.i

src/CMakeFiles/src.dir/stock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/stock.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/stock.cpp -o CMakeFiles/src.dir/stock.cpp.s

src/CMakeFiles/src.dir/portfolio.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/portfolio.cpp.o: src/portfolio.cpp
src/CMakeFiles/src.dir/portfolio.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/portfolio.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/portfolio.cpp.o -MF CMakeFiles/src.dir/portfolio.cpp.o.d -o CMakeFiles/src.dir/portfolio.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/portfolio.cpp

src/CMakeFiles/src.dir/portfolio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/portfolio.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/portfolio.cpp > CMakeFiles/src.dir/portfolio.cpp.i

src/CMakeFiles/src.dir/portfolio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/portfolio.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/portfolio.cpp -o CMakeFiles/src.dir/portfolio.cpp.s

src/CMakeFiles/src.dir/driver.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/driver.cpp.o: src/driver.cpp
src/CMakeFiles/src.dir/driver.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/driver.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/driver.cpp.o -MF CMakeFiles/src.dir/driver.cpp.o.d -o CMakeFiles/src.dir/driver.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/driver.cpp

src/CMakeFiles/src.dir/driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/driver.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/driver.cpp > CMakeFiles/src.dir/driver.cpp.i

src/CMakeFiles/src.dir/driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/driver.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/driver.cpp -o CMakeFiles/src.dir/driver.cpp.s

src/CMakeFiles/src.dir/strlib.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/strlib.cpp.o: src/strlib.cpp
src/CMakeFiles/src.dir/strlib.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/strlib.cpp.o"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/strlib.cpp.o -MF CMakeFiles/src.dir/strlib.cpp.o.d -o CMakeFiles/src.dir/strlib.cpp.o -c /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/strlib.cpp

src/CMakeFiles/src.dir/strlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/strlib.cpp.i"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/strlib.cpp > CMakeFiles/src.dir/strlib.cpp.i

src/CMakeFiles/src.dir/strlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/strlib.cpp.s"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/strlib.cpp -o CMakeFiles/src.dir/strlib.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/money.cpp.o" \
"CMakeFiles/src.dir/stock.cpp.o" \
"CMakeFiles/src.dir/portfolio.cpp.o" \
"CMakeFiles/src.dir/driver.cpp.o" \
"CMakeFiles/src.dir/strlib.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/money.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/stock.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/portfolio.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/driver.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/strlib.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libsrc.a"
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src /Users/connieashleyxu/Downloads/ITP365/hw03-connieashleyxu/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

