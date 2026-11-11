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

Urgencia * Urgencia::clonar() const {
    return new Urgencia(*this);
}

void Urgencia::leer(ifstream &input, int hora) {
    Atencion::leer(input, hora);

    getline(input, zona_lesion, ',');
    input>>necesita_rx;
    input.get();
}

Urgencia::Urgencia() {
    necesita_rx = false;
}

Urgencia::Urgencia(const class Urgencia &other) {
    necesita_rx = false;
    *this = other;
}
