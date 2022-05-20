cmake_minimum_required(VERSION 3.22)
project(PaccerLib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PaccerLib
        PaccerLib.cpp
        PaccerLib.h)
