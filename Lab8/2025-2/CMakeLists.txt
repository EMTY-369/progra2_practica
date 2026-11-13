cmake_minimum_required(VERSION 4.3)
project(2025_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(2025_2 main.cpp
        Bibliotecas/Utils/Utils.cpp
        Bibliotecas/Utils/Utils.hpp
        Bibliotecas/Model/Metrica.cpp
        Bibliotecas/Model/Metrica.hpp
        Bibliotecas/Model/MetricaBasica.cpp
        Bibliotecas/Model/MetricaBasica.hpp
        Bibliotecas/Model/MetricaEngagement.cpp
        Bibliotecas/Model/MetricaEngagement.hpp
        Bibliotecas/Model/MetricaCalidad.cpp
        Bibliotecas/Model/MetricaCalidad.hpp
        Bibliotecas/Structs/Nodo.cpp
        Bibliotecas/Structs/Nodo.hpp
        Bibliotecas/Structs/Lista.cpp
        Bibliotecas/Structs/Lista.hpp
        Bibliotecas/Model/AdministrarMetricas.cpp
        Bibliotecas/Model/AdministrarMetricas.hpp
        Bibliotecas/Structs/NodoABB.cpp
        Bibliotecas/Structs/NodoABB.hpp
        Bibliotecas/Structs/ArbolABB.cpp
        Bibliotecas/Structs/ArbolABB.hpp)
