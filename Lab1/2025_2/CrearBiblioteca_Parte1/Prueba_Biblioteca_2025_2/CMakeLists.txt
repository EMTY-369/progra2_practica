cmake_minimum_required(VERSION 4.3)
project(Prueba_Biblioteca_2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Prueba_Biblioteca_2025_2 main.cpp
        Bibliotecas/Sobrecargas.hpp
        Bibliotecas/Utils.hpp
        Estructuras/Estructuras.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(Prueba_Biblioteca_2025_2 PRIVATE Sobrecargas)
