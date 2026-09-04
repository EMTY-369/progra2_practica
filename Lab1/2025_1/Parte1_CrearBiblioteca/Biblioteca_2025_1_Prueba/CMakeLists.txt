cmake_minimum_required(VERSION 4.3)
project(Biblioteca_2025_1_Prueba)

set(CMAKE_CXX_STANDARD 20)

add_executable(Biblioteca_2025_1_Prueba main.cpp
        Bibliotecas/Models/CadenaDeCaracteres.hpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Utils/Fuciones.cpp
        Bibliotecas/Utils/Fuciones.hpp
        Bibliotecas/Sobrecargas.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(Biblioteca_2025_1_Prueba PRIVATE Sobrecargas)
