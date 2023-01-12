cmake_minimum_required(VERSION 3.1.6)

project(cpp_test)

#build type
set(CMAKE_BUILD_TYPE "Release")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(cpp_test demo.cpp)

