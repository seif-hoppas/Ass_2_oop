cmake_minimum_required(VERSION 3.21)
project(OOP_ASS2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOP_ASS2
        BigDecimalIntClass.cpp
        BigDecimalIntClass.h
        BigReal.cpp
        BigReal.h
        main.cpp)
