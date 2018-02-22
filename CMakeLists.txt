# Version check
cmake_minimum_required (VERSION 3.0)

# Project
project(special_paths)

# Add files
if(WIN32)
	file(GLOB sources "*_win.cpp")
else()
	file(GLOB sources "*_nix.cpp")
endif()

# Add library
add_library(special_paths STATIC ${sources})

# Compiler Options
target_compile_options(special_paths PRIVATE -fexceptions -std=c++14 -O3 -Wall -pedantic-errors -pedantic)