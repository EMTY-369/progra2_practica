cmake_minimum_required(VERSION 4.3)
project(Fuentes_Biblioteca_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fuentes_Biblioteca_2024_2 main.cpp
        Bibliotecas/Models/Estructuras.h
        Bibliotecas/Utils/Utils.hpp
       Bibliotecas/Sobrecargas.cpp
        Bibliotecas/Sobrecargas.hpp
        Bibliotecas/Utils/FuncionesAuxiliares.cpp
        Bibliotecas/Utils/FuncionesAuxiliares.hpp
)
