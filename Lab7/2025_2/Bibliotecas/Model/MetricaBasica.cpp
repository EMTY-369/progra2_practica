//
// Created by User on 5/11/2026.
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

    input >> horas_transmitidas;
    input.get();
    input >> espectadores_promedio;
    input.get();
}

void MetricaBasica::imprimir(ofstream &output) {
    output<<setw(4)<<""<<"MB-";
    Metrica::imprimir(output, true);
    output<<setw(10)<<horas_transmitidas<<setw(10)<<espectadores_promedio<<"M"<<setw(5)<<"";
    Metrica::imprimir(output, false);
}

bool MetricaBasica::get_estado() {
    return Metrica::is_estado();
}

MetricaBasica::MetricaBasica() {
    horas_transmitidas = 0;
    espectadores_promedio = 0;
}

MetricaBasica::MetricaBasica(const class MetricaBasica &origin) {
    *this = origin;
}
