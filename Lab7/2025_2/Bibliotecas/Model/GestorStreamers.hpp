//
// Created by User on 5/11/2026.
//

#ifndef INC_2025_2_GESTORSTREAMERS_HPP
#define INC_2025_2_GESTORSTREAMERS_HPP
#include "StreamerGratuito.hpp"
#include "StreamerPago.hpp"

class GestorStreamers {
public:
    void cargar_datos_streamers(const string &file_name);
    void buscar_streamer(int id_streamer, int &categoria, int &pos_streamer);
    void actualizar_datos_metricas(const string &file_name);
    void generar_reportes();

    GestorStreamers();
    ~GestorStreamers();
private:
    class StreamerGratuito *streamers_gratuitos;
    class StreamerPago *streamers_pagados;
    int cantidad_gratuitos;
    int cantidad_pagados;
};


#endif //INC_2025_2_GESTORSTREAMERS_HPP
