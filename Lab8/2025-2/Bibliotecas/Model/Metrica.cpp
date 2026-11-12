//
// Created by User on 12/11/2026.
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

    input>>id;
    input.get();
    getline(input,descripcion,',');
    fecha_calculo = Utils::leer_fecha(input);
    fecha_expiracion = Utils::leer_fecha(input);
    if (fecha_expiracion < FECHA_ACTUAL) estado = true;
    else estado = false;
}

void Metrica::imprimir_encabezado(ofstream &output) {
    output<<left<<setw(6)<<""<<setw(11)<<"Código"<<setw(30)<<"Descripción"<<setw(20)<<"Fecha Calc."<<setw(15)<<"Expira"
          <<setw(15)<<"Estado"<<right;
}

void Metrica::imprimir(ofstream &output) {
    output<<left<<setw(6)<<""<<setw(10)<<id<<setw(30)<<descripcion<<setw(20)<<fecha_calculo<<setw(15)<<fecha_expiracion;
    if (estado) output<<setw(15)<<"ACTIVA";
    else output<<setw(15)<<"NO ACTIVA";
    output<<right;
}

Metrica::Metrica() {
    id = 0;
    fecha_calculo = 0;
    fecha_expiracion = 0;
    estado = false;
}

Metrica::Metrica(const Metrica &other) {
    id = 0;
    fecha_calculo = 0;
    fecha_expiracion = 0;
    estado = false;
    *this = other;
}
