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
        Bibliotecas/Model/Streamer.cpp
        Bibliotecas/Model/Streamer.hpp
        Bibliotecas/Model/StreamerGratuito.cpp
        Bibliotecas/Model/StreamerGratuito.hpp
        Bibliotecas/Model/StreamerPago.cpp
        Bibliotecas/Model/StreamerPago.hpp
        Bibliotecas/Model/GestorStreamers.cpp
        Bibliotecas/Model/GestorStreamers.hpp)
