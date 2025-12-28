cmake_minimum_required(VERSION 4.1)
project(usaco_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(usaco_cpp milkmix.cpp
        boilerplate.cpp
        race.cpp
        race.h
        milkorder.cpp
        milkorder.h
        drought.cpp
        drought.h
        outofplace.cpp
        outofplace.h
)
