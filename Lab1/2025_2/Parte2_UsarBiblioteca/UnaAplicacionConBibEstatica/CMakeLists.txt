cmake_minimum_required(VERSION 4.3)
project(UnaAplicacionConBibEstatica)

set(CMAKE_CXX_STANDARD 20)

add_executable(UnaAplicacionConBibEstatica main.cpp
        Bibliotecas/Sobrecargas.hpp
        Bibliotecas/Utils.hpp
        Estructuras/Estructuras.h
        Bibliotecas/Funciones.cpp
        Bibliotecas/Funciones.hpp
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR}/Bibliotecas")

target_link_libraries(UnaAplicacionConBibEstatica PRIVATE Sobrecargas)
