//
// Created by User on 4/11/2026.
//

#include "Cita.hpp"

int Cita::get_fecha() const {
    return fecha;
}

void Cita::set_fecha(const int fecha) {
    this->fecha = fecha;
}

int Cita::get_hora() const {
    return hora;
}

void Cita::set_hora(const int hora) {
    this->hora = hora;
}

class Mascota Cita::get_amascota() const {
    return Amascota;
}

void Cita::set_amascota(const class Mascota &amascota) {
    Amascota = amascota;
}

void Cita::leer(ifstream &input) {
    int dd, mm, aa;
    char c;
    input >> dd >> c >> mm >> c >> aa >> c;
    fecha = aa*10000 + mm*100 + dd;
    input >> hora >> c;
    Amascota.leer(input);
}

void Cita::imprimir(ofstream &output) {
    Utils::imprimir_fecha(fecha, output);
    output<<setw(6)<<""<<setw(2)<<hora<<":00   ";
    Amascota.imprimir(output);
}

Cita::Cita() {
    fecha=0;
    hora=0;
}

Cita::Cita(const class Cita &other) {
    *this = other;
}
