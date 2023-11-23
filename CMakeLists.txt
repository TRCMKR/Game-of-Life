cmake_minimum_required(VERSION 3.26)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)



add_executable(GameOfLife
        main.cpp
        gameOfLife.cpp
        gameOfLife.h
        colors.h
        colors.cpp
        universe.cpp
        universe.h
        matrix.h

)
