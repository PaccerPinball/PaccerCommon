cmake_minimum_required(VERSION 3.22)
project(PaccerCommon)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(..\\PaccerInput)
include_directories(..\\PaccerOutput)
include_directories("C:\\Program Files (x86)\\Arduino\\libraries\\LiquidCrystal\\src")
include_directories("C:\\Program Files (x86)\\Arduino\\hardware\\arduino\\avr\\cores\\arduino")

add_executable(PaccerCommon
        PaccerCommon.cpp
        PaccerCommon.h)
