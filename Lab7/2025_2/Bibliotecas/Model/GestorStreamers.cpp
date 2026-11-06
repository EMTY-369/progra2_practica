//
// Created by User on 5/11/2026.
//

#include "GestorStreamers.hpp"

void GestorStreamers::cargar_datos_streamers(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);
    streamers_gratuitos = new StreamerGratuito[MAX_STREAMERS];
    streamers_pagados = new StreamerPago[MAX_STREAMERS];
    //Gratuito,
    while (true) {
        string categoria;
        getline(input, categoria, ',');
        if (input.eof()) break;
        if (categoria == "Gratuito") {
            streamers_gratuitos[cantidad_gratuitos++].leer(input);
        } else if (categoria == "Pagado") {
            streamers_pagados[cantidad_pagados++].leer(input);
        } else {
            input.ignore(200, '\n');
        }
    }
    input.close();
}

void GestorStreamers::buscar_streamer(int id_streamer, int &categoria, int &pos_streamer) {
    for (int i = 0; i < cantidad_gratuitos; i++) {
        if (streamers_gratuitos[i].get_id() == id_streamer) {
            pos_streamer = i;
            categoria = 1;
        }
    }

    for (int i = 0; i < cantidad_pagados; i++) {
        if (streamers_pagados[i].get_id() == id_streamer) {
            categoria = 2;
            pos_streamer = i;
        }
    }
}

void GestorStreamers::actualizar_datos_metricas(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        string tipo;
        getline(input, tipo, ',');
        if (input.eof()) break;
        int id_streamer, categoria=0, pos_streamer=-1;
        input>>id_streamer;
        input.get();
        buscar_streamer(id_streamer, categoria, pos_streamer);
        if (pos_streamer!=-1) {
            if (categoria == 1) streamers_gratuitos[pos_streamer].actualizar(tipo, input);
            else streamers_pagados[pos_streamer].actualizar(tipo, input);
        }
        else input.ignore(200, '\n');
    }
    input.close();
}

void GestorStreamers::generar_reportes() {
    ofstream output;
    string base = "Reporte/";
    for (int i = 0; i < cantidad_gratuitos; i++) {
        string nombre = base + "Gratuito/" + streamers_gratuitos[i].get_cuenta() + "_" + streamers_gratuitos[i].get_categoria() + "_"
                         + to_string(streamers_gratuitos[i].get_fecha_fin_trial()) + ".txt";
        Utils::abrir_archivo(output, nombre);
        output<<fixed;
        output.precision(2);
        streamers_gratuitos[i].imprimir(output);
        output.close();
    }

    // for (int i = 0; i < cantidad_pagados; i++) {
    //     string nombre = base + "Pagado/" + streamers_pagados[i].get_cuenta() + "_" + streamers_pagados[i].get_categoria() + "_"
    //                      + to_string(streamers_pagados[i].get_fecha_inicio_plan()) + ".txt";
    //     Utils::abrir_archivo(output, nombre);
    //     output<<fixed;
    //     output.precision(2);
    //     streamers_pagados[i].imprimir(output);
    //     output.close();
    // }
}

GestorStreamers::GestorStreamers() {
    streamers_gratuitos=nullptr;
    streamers_pagados=nullptr;
    cantidad_gratuitos=0;
    cantidad_pagados=0;
}

GestorStreamers::~GestorStreamers() {
    delete [] streamers_gratuitos;
    delete [] streamers_pagados;
}
