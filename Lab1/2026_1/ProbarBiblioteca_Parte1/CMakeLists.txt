cmake_minimum_required(VERSION 4.3)
project(ProbarBiblioteca_Parte1)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProbarBiblioteca_Parte1 main.cpp
        Bibliotecas/Utils.hpp
        Estructuras/Mascota.hpp
        Estructuras/Veterinario.hpp
        Estructuras/Atencion.hpp
        Estructuras/SistemaHuellitas.hpp
        Bibliotecas/SobreCargas.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(ProbarBiblioteca_Parte1 PRIVATE Sobrecarga)