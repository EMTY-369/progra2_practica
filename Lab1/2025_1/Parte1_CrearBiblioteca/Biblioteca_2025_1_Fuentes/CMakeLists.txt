cmake_minimum_required(VERSION 4.3)
project(Biblioteca_2025_1_Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_2025_1_Fuentes main.cpp
        Estructuras/CadenaDeCaracteres.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Fuciones.cpp
        Bibliotecas/Fuciones.hpp
        Bibliotecas/Sobrecargas.cpp
        Bibliotecas/Sobrecargas.hpp
)
