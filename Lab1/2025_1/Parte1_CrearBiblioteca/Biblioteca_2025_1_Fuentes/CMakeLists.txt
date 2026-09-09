cmake_minimum_required(VERSION 4.3)
project(Biblioteca_2025_1_Fuentes)

set(CMAKE_CXX_STANDARD 20)

add_library(Sobrecargas STATIC Bibliotecas/Sobrecargas.cpp)

add_executable(Biblioteca_2025_1_Fuentes main.cpp
        Bibliotecas/Models/CadenaDeCaracteres.hpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Utils/Fuciones.cpp
        Bibliotecas/Utils/Fuciones.hpp
        Bibliotecas/Sobrecargas.hpp
)

target_link_libraries(Biblioteca_2025_1_Fuentes Sobrecargas)
