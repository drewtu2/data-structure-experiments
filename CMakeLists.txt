cmake_minimum_required (VERSION 3.0)
project (DataStructuresTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )

add_subdirectory (lru_cache)
add_subdirectory (circular_buffer)
add_subdirectory (demo)


