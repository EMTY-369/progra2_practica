//
// Created by User on 4/11/2026.
//

#include "Mascota.hpp"

int Mascota::get_codigo() const {
    return codigo;
}

void Mascota::set_codigo(const int codigo) {
    this->codigo = codigo;
}

string Mascota::get_nombre() const {
    return nombre;
}

void Mascota::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

char Mascota::get_tipo() const {
    return tipo;
}

void Mascota::set_tipo(const char tipo) {
    this->tipo = tipo;
}

string Mascota::get_raza() const {
    return raza;
}

void Mascota::set_raza(const string &raza) {
    this->raza = raza;
}

void Mascota::leer(ifstream &input) {
    input >> codigo;
    input.get();
    getline(input,nombre, ',');
    input >> tipo;
    input.get();
    getline(input,raza, ',');
}

void Mascota::imprimir(ofstream &output) {
    output<<left<<setw(16)<<raza<<setw(20)<<nombre<<right;
}

Mascota::Mascota() {
    codigo = 0;
    tipo = 0;
}

Mascota::Mascota(const class Mascota &origen) {
    *this = origen;
}
