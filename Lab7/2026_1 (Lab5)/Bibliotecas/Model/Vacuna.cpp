//
// Created by User on 4/11/2026.
//

#include "Vacuna.hpp"

int Vacuna::get_dosis() const {
    return dosis;
}

void Vacuna::set_dosis(const int dosis) {
    this->dosis = dosis;
}

int Vacuna::get_meses() const {
    return meses;
}

void Vacuna::set_meses(const int meses) {
    this->meses = meses;
}

void Vacuna::leer(ifstream &input) {
    Cita::leer(input);
    input >> dosis;
    input.get();
    input >> meses;
}

void Vacuna::imprimir(ofstream &output) {
    Cita::imprimir(output);
    output << setw(6)<<dosis<<setw(20)<<meses<<endl;
}

Vacuna::Vacuna() {
    dosis = 0;
    meses = 0;
}

Vacuna::Vacuna(const class Vacuna &origin) {
    *this = origin;
}
