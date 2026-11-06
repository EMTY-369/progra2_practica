//
// Created by User on 5/11/2026.
//

#include "Metrica.hpp"

int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(const int id) {
    this->id = id;
}

string Metrica::get_descripcion() const {
    return descripcion;
}

void Metrica::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(const int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(const int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(const bool estado) {
    this->estado = estado;
}

void Metrica::leer(ifstream &input) {
    input >> id;
    input.get();
    getline(input, descripcion,',');
    fecha_calculo = Utils::leer_fecha(input);
    input.get();
    fecha_expiracion = Utils::leer_fecha(input);
    input.get();

    int fecha_actual = 20251105;
    if (fecha_actual<fecha_expiracion) estado=true;
}

void Metrica::imprimir(ofstream &output, bool cond) const {
    if (cond) {
        output<<setw(4)<<setfill('0')<<id<<setfill(' ')<<setw(12)<<fecha_calculo<<setw(20)<<fecha_expiracion<<setw(12)<<"";
        if (is_estado()) output<<"ACTIVA";
        else output<<"EXPIRADA";
    } else {
        output<<descripcion<<endl;
    }
}

Metrica::Metrica() {
    id=0;
    fecha_calculo=0;
    fecha_expiracion=0;
    estado=false;
}

Metrica::Metrica(const class Metrica &origin) {
    *this = origin;
}
