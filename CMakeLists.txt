cmake_minimum_required(VERSION 3.30)
project(TourOfCPPActivity)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(TourOfCPPActivity Source/main.cpp
        Source/chapter1/chapter1.cpp
        Source/chapter2/chapter2.cpp
        Source/printer.cpp
        Source/printer.h
        Source/chapter3/chapter3.cpp
        Source/chapter3/Vector.cpp
        Source/chapter3/Vector.h
)
