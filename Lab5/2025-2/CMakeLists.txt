cmake_minimum_required(VERSION 4.3)
project(2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_2 main.cpp
        Models/Streamer.cpp
        Models/Streamer.hpp
        Models/Utils.cpp
        Models/Utils.hpp
        Models/GestorStreamers.cpp
        Models/GestorStreamers.hpp)
