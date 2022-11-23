cmake_minimum_required(VERSION 3.22)
project(Rabin_Karp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
set (SOURCE_FILES tests/algoTest.cpp src/RabinKarp.h)

include_directories(lib/googletest/googletest/include)
add_executable(Rabin_Karp ${SOURCE_FILES})
target_link_libraries(Rabin_Karp gtest gtest_main)