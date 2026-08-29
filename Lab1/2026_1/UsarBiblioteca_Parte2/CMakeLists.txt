cmake_minimum_required(VERSION 4.3)
project(UsarBiblioteca_Parte2)

set(CMAKE_CXX_STANDARD 20)

add_executable(UsarBiblioteca_Parte2 main.cpp
        Bibliotecas/Utils.hpp
        Estructuras/Mascota.hpp
        Estructuras/Veterinario.hpp
        Estructuras/Atencion.hpp
        Estructuras/SistemaHuellitas.hpp
        Bibliotecas/SobreCargas.hpp
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(UsarBiblioteca_Parte2 PRIVATE Sobrecarga)
