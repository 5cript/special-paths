# Version check
cmake_minimum_required (VERSION 3.17)

# Project
project(special_paths)

# Add files
if(WIN32)
	set(sources "src/special-paths/special_paths_win.cpp")
else()
	set(sources "src/special-paths/special_paths_nix.cpp")
endif()

# Add library
add_library(special_paths STATIC ${sources})

# Compiler Options
target_compile_features(special_paths PRIVATE cxx_std_20)
target_compile_options(special_paths PRIVATE -fexceptions -O3 -Wall -pedantic-errors -pedantic)
target_include_directories(special_paths PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")