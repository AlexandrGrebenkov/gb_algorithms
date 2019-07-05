cmake_minimum_required(VERSION 3.14)
project(Lesson1)

set(CMAKE_CXX_STANDARD 11)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(Lesson1 main.cpp HomeWork.c HomeWork.h Tests.cpp Tests.h)
target_link_libraries(Lesson1 gtest gtest_main)
