cmake_minimum_required(VERSION 3.26)
project(Cars_for_Nikita)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cars_for_Nikita main.cpp
        description.h
        functions.h
        adding_functions.cpp
        functions.cpp
        adding_functions.h)
