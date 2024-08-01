cmake_minimum_required(VERSION 3.27)
project(wordHunter)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(wordHunter
        Board.h
        Dictionary.h
        formatted_dictionary.csv
        main.cpp)
