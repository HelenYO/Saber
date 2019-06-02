cmake_minimum_required(VERSION 3.13)
project(Saber)

set(CMAKE_CXX_STANDARD 17)
include_directories(${Saber_SOURCE_DIR})

add_executable(testing testing.cpp
        gtest/gtest-all.cc
        gtest/gtest.h
        gtest/gtest_main.cc)

add_library(Saber SHARED lib/List.cpp lib/List.h )
target_link_libraries(testing Saber)

#add_executable(Saber
#        main.cpp
#        List.cpp
#        List.h
#        testing.cpp)˚