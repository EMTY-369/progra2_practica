//
// Created by User on 11/11/2026.
//

#include "Emergencia.hpp"

bool Emergencia::is_requiere_rcp() const {
    return requiere_rcp;
}

void Emergencia::set_requiere_rcp(const bool requiere_rcp) {
    this->requiere_rcp = requiere_rcp;
}

int Emergencia::get_minutos_sin_pulso() const {
    return minutos_sin_pulso;
}

void Emergencia::set_minutos_sin_pulso(const int minutos_sin_pulso) {
    this->minutos_sin_pulso = minutos_sin_pulso;
}

int Emergencia::obtener_prioridad() {
    return 1;
}

int Emergencia::obtener_llave() {
    return 1*10000 + get_codigo();
}

Emergencia * Emergencia::clonar() const{
    return new Emergencia(*this);
}

void Emergencia::leer(ifstream &input, int hora) {
    Atencion::leer(input, hora);

    input>>requiere_rcp;
    input.get();
    input>>minutos_sin_pulso;
    input.get();
}

void Emergencia::imprimir(ofstream &output) {
    Atencion::imprimir(output);

    if(requiere_rcp) output<<setw(10)<<"SI";
    else output<<setw(10)<<"NO";
    output<<setw(9)<<minutos_sin_pulso;
    output<<endl;
}

Emergencia::Emergencia() {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
}

Emergencia::Emergencia(const class Emergencia &other) {
    requiere_rcp = false;
    minutos_sin_pulso = 0;
    *this = other;
}

Emergencia::~Emergencia() {
    cout << "Destruyendo Emergencia" << endl;
}
