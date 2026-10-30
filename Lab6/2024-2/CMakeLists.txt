cmake_minimum_required(VERSION 4.3)
project(2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(2024_2 main.cpp
        Biblioteca/Cliente.cpp
        Biblioteca/Cliente.hpp
        Biblioteca/Plato.cpp
        Biblioteca/Plato.hpp
        Biblioteca/Utils.cpp
        Biblioteca/Utils.hpp
        Biblioteca/Restaurante.cpp
        Biblioteca/Restaurante.hpp)
