//
// Created by User on 12/11/2026.
//

#include "MetricaBasica.hpp"

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(const double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(const int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream &input) {
    Metrica::leer(input);

    input>>horas_transmitidas;
    input.get();
    input>>espectadores_promedio;
    input.get();
}

int MetricaBasica::obtenerTipoMetrica() {
    return  1;
}

void MetricaBasica::imprimir_encabezado(ofstream &output) {
    output<<"[METRICAS BASIC]"<<endl;
    Metrica::imprimir_encabezado(output);
    output<<"Horas"<<setw(12)<<"Viewers"<<endl;
}

void MetricaBasica::imprimir(ofstream &output) const {
    Metrica::imprimir(output);
    output<<setw(6)<<horas_transmitidas<<setw(8)<<espectadores_promedio<<"M"<<endl;
}

MetricaBasica::MetricaBasica() {
    horas_transmitidas = 0;
    espectadores_promedio = 0;
}

MetricaBasica::MetricaBasica(const MetricaBasica &other)  : Metrica(other) {
    horas_transmitidas = 0;
    espectadores_promedio = 0;
    *this = other;
}
