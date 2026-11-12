//
// Created by User on 11/11/2026.
//

#include "Urgencia.hpp"

string Urgencia::get_zona_lesion() const {
    return zona_lesion;
}

void Urgencia::set_zona_lesion(const string &zona_lesion) {
    this->zona_lesion = zona_lesion;
}

bool Urgencia::is_necesita_rx() const {
    return necesita_rx;
}

void Urgencia::set_necesita_rx(const bool necesita_rx) {
    this->necesita_rx = necesita_rx;
}

int Urgencia::obtener_prioridad() {
    return 2;
}

int Urgencia::obtener_llave() {
    return 2*10000 + get_codigo();
}

Urgencia * Urgencia::clonar() const {
    return new Urgencia(*this);
}

void Urgencia::leer(ifstream &input, int hora) {
    Atencion::leer(input, hora);

    getline(input, zona_lesion, ',');
    input>>necesita_rx;
    input.get();
}

void Urgencia::imprimir(ofstream &output) {
    Atencion::imprimir(output);

    output<<setw(30)<<zona_lesion;
    if (necesita_rx) output<<setw(10)<<"SI";
    else output<<setw(10)<<"NO";
    output<<endl;
}

Urgencia::Urgencia() {
    necesita_rx = false;
}

Urgencia::Urgencia(const class Urgencia &other) {
    necesita_rx = false;
    *this = other;
}

Urgencia::~Urgencia() {
    cout << "Destruyendo Urgencia" << endl;
}
