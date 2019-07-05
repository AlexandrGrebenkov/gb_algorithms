cmake_minimum_required(VERSION 3.14)
project(Lesson1)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Lesson1 main.cpp HomeWork.c HomeWork.h)
target_link_libraries(Lesson1 gtest gtest_main)
