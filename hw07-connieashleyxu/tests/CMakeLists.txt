# �2023 Nathan Greenfield
# Require CMAKE 3.1 or higher
cmake_minimum_required(VERSION 3.1)

# Setup headers and source code
set(HEADER_FILES
    catch.hpp
    ITPMemLeaks.h
)

set(SOURCE_FILES
    catch.cpp
	studentTests.cpp
    ITPMemLeaks.cpp
)

# Where any include files are
include_directories("../src")

# Don't change this
add_executable(tests ${SOURCE_FILES})

# Link main vs the source library
target_link_libraries(tests src)
