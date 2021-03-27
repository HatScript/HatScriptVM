cmake_minimum_required(VERSION 3.17)
project(HatScript)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(HatScriptVM)
add_subdirectory(HatScriptREPL)
add_subdirectory(Google_tests)