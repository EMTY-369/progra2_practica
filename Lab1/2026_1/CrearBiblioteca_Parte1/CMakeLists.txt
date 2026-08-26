cmake_minimum_required(VERSION 4.3)
project(CrearBiblioteca_Parte1)

set(CMAKE_CXX_STANDARD 20)

add_executable(CrearBiblioteca_Parte1 main.cpp
        Bibliotecas/Utils.hpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp
        Estructuras/Mascota.hpp
        Estructuras/Veterinario.hpp
        Estructuras/Atencion.hpp
        Estructuras/SistemaHuellitas.hpp
        Bibliotecas/SobreCargas.cpp
        Bibliotecas/SobreCargas.hpp
)
