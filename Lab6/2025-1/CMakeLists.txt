cmake_minimum_required(VERSION 4.3)
project(2025_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_1 main.cpp
        Bibliotecas/Utils.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.hpp
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.hpp
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.hpp
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.hpp
)
