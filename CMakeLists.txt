cmake_minimum_required(VERSION 3.17)
project(HatScript)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(HatScriptVM)
add_subdirectory(HatScriptREPL)
enable_testing()
include(GoogleTest)
add_subdirectory(tests)
