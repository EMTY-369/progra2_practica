//
// Created by User on 11/11/2026.
//

#include "Atencion.hpp"

int Atencion::get_codigo() const {
    return codigo;
}

void Atencion::set_codigo(const int codigo) {
    this->codigo = codigo;
}

string Atencion::get_paciend() const {
    return paciente;
}

void Atencion::set_paciend(const string &paciend) {
    this->paciente = paciend;
}

string Atencion::get_descripcion() const {
    return descripcion;
}

void Atencion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

int Atencion::get_hora() const {
    return hora;
}

void Atencion::set_hora(const int hora) {
    this->hora = hora;
}

void Atencion::leer(ifstream &input, int hora) {
    input>>codigo;
    input.get();
    getline(input,paciente,',');
    getline(input,descripcion,',');
    this->hora = hora;
}

Atencion::Atencion() {
    codigo = 0;
    hora = 0;
}

Atencion::Atencion(const class Atencion &other) {
    codigo = 0;
    hora = 0;
    *this = other;
}
