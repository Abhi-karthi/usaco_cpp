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
        sleeping.cpp
        sleeping.h
        balancing.cpp
        balancing.h
        back_to_back.cpp
        back_to_back.h
        fast_and_furious.cpp
        fast_and_furious.h
        cowvid19.cpp
        cowvid19.h
        usacow.cpp
        usacow.h
        cownomics.cpp
        cownomics.h
)
