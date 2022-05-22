cmake_minimum_required(VERSION 3.22)
project(PaccerCommon)

set(CMAKE_CXX_STANDARD 14)

add_compile_definitions(__AVR_ATmega328P__=1)

include_directories(.)
include_directories(..\\PaccerInput)
include_directories(..\\PaccerOutput)
include_directories("C:\\Program Files (x86)\\Arduino\\libraries\\LiquidCrystal\\src")
include_directories("C:\\Program Files (x86)\\Arduino\\hardware\\arduino\\avr\\cores\\arduino")
include_directories("C:\\Program Files (x86)\\Arduino\\hardware\\tools\\avr\\avr\\include")

add_executable(PaccerCommon
        PaccerCommon.cpp
        PaccerCommon.h)
