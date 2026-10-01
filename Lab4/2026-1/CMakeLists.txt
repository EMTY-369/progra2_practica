cmake_minimum_required(VERSION 4.3)
project(2026_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2026_1 main.cpp
        Bibliotecas/BibliotecaGenerica.cpp
        Bibliotecas/BibliotecaGenerica.hpp
        Bibliotecas/BibliotecaRegistros.cpp
        Bibliotecas/BibliotecaRegistros.hpp
        Bibliotecas/BibliotecasEnteros.cpp
        Bibliotecas/BibliotecasEnteros.hpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Helpers.cpp
        Bibliotecas/Helpers.hpp
)
