cmake_minimum_required(VERSION 3.14)
project(GB_Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(GB_Algorithms main.cpp Lesson1.c Lesson1.h Lesson1_Tests.cpp Lesson2.c Lesson2.h Lesson2_Tests.cpp)
target_link_libraries(GB_Algorithms gtest gtest_main)
