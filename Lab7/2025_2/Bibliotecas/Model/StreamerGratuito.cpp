//
// Created by User on 5/11/2026.
//

#include "StreamerGratuito.hpp"

int StreamerGratuito::get_fecha_fin_trial() const {
    return fecha_fin_trial;
}

void StreamerGratuito::set_fecha_fin_trial(const int fecha_fin_trial) {
    this->fecha_fin_trial = fecha_fin_trial;
}

class MetricaBasica * StreamerGratuito::get_metricas_basicas() const {
    return metricas_basicas;
}

void StreamerGratuito::set_metricas_basicas(class MetricaBasica * const metricas_basicas) {
    this->metricas_basicas = metricas_basicas;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerGratuito::set_cantidad_metricas_basicas(const int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

void StreamerGratuito::leer(ifstream &input) {
    Streamer::leer(input);

    metricas_basicas = new MetricaBasica[MAX_ELE];
    fecha_fin_trial = Utils::leer_fecha(input);
}

void StreamerGratuito:: imprimir_info(bool cond, ofstream &output, int &n_activas, int &n_expiradas) {
    double hora_totales=0;
    int mayor_espect=0;
    for (int i = 0; i < cantidad_metricas_basicas; i++) {
        if (cond) metricas_basicas[i].imprimir(output);
        else {
            hora_totales+=metricas_basicas[i].get_horas_transmitidas();
            if (mayor_espect<metricas_basicas[i].get_espectadores_promedio()) mayor_espect=metricas_basicas[i].get_espectadores_promedio();
            if (metricas_basicas[i].get_estado()) n_activas++;
            else n_expiradas++;
        }
    }

    if (not cond) {
        output<<"[BASIC] HORAS_TOT:"<<setw(8)<<hora_totales<<" | VIEWERS_PROM_GLOBAL:"<<setw(6)<<mayor_espect;
        output<<" | ACTICAS:"<<setw(3)<<n_activas<<" | EXPIRADAS:"<<setw(3)<<n_expiradas<<endl;
    }
}

void StreamerGratuito::imprimir(ofstream &output, int &n_activas, int &n_expiradas) {

    Streamer::imprimir(output);
    imprimir_info(false, output, n_activas, n_expiradas);

    output<<setw(4)<<""<<left<<setw(12)<<"Código"<<setw(20)<<"Fecha Calc."<<setw(20)<<"Expira";
    output<<setw(12)<<"Estado"<<setw(10)<<"Horas"<<setw(10)<<"Viewers"<<"Descripción"<<endl<<right;

    imprimir_info(true, output, n_activas, n_expiradas);
}

void StreamerGratuito::actualizar(const string &tipo, ifstream &input) {
    if (tipo == "BASIC") {
        metricas_basicas[cantidad_metricas_basicas++].leer(input);
    }
}

StreamerGratuito::StreamerGratuito() {
    fecha_fin_trial = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_basicas = 0;
}

StreamerGratuito::~StreamerGratuito() {
    delete[] metricas_basicas;
}
