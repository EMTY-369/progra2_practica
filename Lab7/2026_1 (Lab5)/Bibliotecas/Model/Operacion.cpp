//
// Created by User on 4/11/2026.
//

#include "Operacion.hpp"

bool Operacion::get_anestesiageneral() const {
    return anestesiageneral;
}

void Operacion::set_anestesiageneral(const bool anestesiageneral) {
    this->anestesiageneral = anestesiageneral;
}

int Operacion::get_nummedicos() const {
    return nummedicos;
}

void Operacion::set_nummedicos(const int nummedicos) {
    this->nummedicos = nummedicos;
}

double Operacion::get_total() const {
    return total;
}

void Operacion::set_total(const double total) {
    this->total = total;
}

void Operacion::leer(ifstream &input) {
    Cita::leer(input);

    input >> total;
    input.get();
    input >> anestesiageneral;
    input.get();
    input >> nummedicos;
}

void Operacion::imprimir(ofstream &output) {
    Cita::imprimir(output);

    output << left;
    if (anestesiageneral) output << setw(14) << "General";
    else output << setw(14) << "Parcial";
    output << right << setw(16) << nummedicos << endl;
}

Operacion::Operacion() {
    anestesiageneral = false;
    nummedicos = 0;
    total = 0;
}

Operacion::Operacion(const class Operacion &origin) {
    *this = origin;
}
