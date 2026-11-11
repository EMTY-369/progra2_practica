//
// Created by User on 5/11/2026.
//

#include "StreamerPago.hpp"

int StreamerPago::get_fecha_inicio_plan() const {
    return fecha_inicio_plan;
}

void StreamerPago::set_fecha_inicio_plan(const int fecha_inicio_plan) {
    this->fecha_inicio_plan = fecha_inicio_plan;
}

class MetricaBasica * StreamerPago::get_metricas_basicas() const {
    return metricas_basicas;
}

void StreamerPago::set_metricas_basicas(class MetricaBasica * const metricas_basicas) {
    this->metricas_basicas = metricas_basicas;
}

int StreamerPago::get_cantidad_metricas_basicas() const {
    return cantidad_metricas_basicas;
}

void StreamerPago::set_cantidad_metricas_basicas(const int cantidad_metricas_basicas) {
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

class MetricaEngagement * StreamerPago::get_metricas_engagements() const {
    return metricas_engagements;
}

void StreamerPago::set_metricas_engagements(class MetricaEngagement * const metricas_engagements) {
    this->metricas_engagements = metricas_engagements;
}

int StreamerPago::get_cantidad_metricas_engagement() const {
    return cantidad_metricas_engagement;
}

void StreamerPago::set_cantidad_metricas_engagement(const int cantidad_metricas_engagement) {
    this->cantidad_metricas_engagement = cantidad_metricas_engagement;
}

class MetricaCalidad * StreamerPago::get_metricas_calidades() const {
    return metricas_calidades;
}

void StreamerPago::set_metricas_calidades(class MetricaCalidad * const metricas_calidades) {
    this->metricas_calidades = metricas_calidades;
}

int StreamerPago::get_cantidad_metricas_calidades() const {
    return cantidad_metricas_calidades;
}

void StreamerPago::set_cantidad_metricas_calidades(const int cantidad_metricas_calidades) {
    this->cantidad_metricas_calidades = cantidad_metricas_calidades;
}

void StreamerPago::leer(ifstream &input) {
    Streamer::leer(input);

    metricas_basicas = new MetricaBasica[MAX_ELE];
    metricas_engagements = new MetricaEngagement[MAX_ELE];
    metricas_calidades = new MetricaCalidad[MAX_ELE];
    fecha_inicio_plan = Utils::leer_fecha(input);
}

void StreamerPago::imprimir(ofstream &output, int &n_activas, int &n_expiradas) {

    Streamer::imprimir(output);

}

void StreamerPago::actualizar(const string &tipo, ifstream &input) {
    if (tipo == "BASIC") {
        metricas_basicas[cantidad_metricas_basicas++].leer(input);
    } else if (tipo == "ENGAGEMENT") {
        metricas_engagements[cantidad_metricas_engagement++].leer(input);
    } else if (tipo == "QUALITY") {
        metricas_calidades[cantidad_metricas_calidades++].leer(input);
    }
}

StreamerPago::StreamerPago() {
    fecha_inicio_plan = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_basicas = 0;
    metricas_engagements = nullptr;
    cantidad_metricas_engagement = 0;
    metricas_calidades = nullptr;
    cantidad_metricas_calidades = 0;
}

StreamerPago::~StreamerPago() {
    delete[] metricas_basicas;
    delete[] metricas_engagements;
    delete[] metricas_calidades;
}
