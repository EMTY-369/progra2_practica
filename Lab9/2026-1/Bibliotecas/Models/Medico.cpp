//
// Created by User on 19/11/2026.
//

#include "Medico.hpp"

int Medico::get_codigo() const {
    return codigo;
}

void Medico::set_codigo(const int codigo) {
    this->codigo = codigo;
}

string Medico::get_nombre() const {
    return nombre;
}

void Medico::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

double Medico::get_tarifa() const {
    return tarifa;
}

void Medico::set_tarifa(const double tarifa) {
    this->tarifa = tarifa;
}

string Medico::get_especialidad_nombre() const {
    return especialidadNombre;
}

void Medico::set_especialidad_nombre(const string &especialidad_nombre) {
    especialidadNombre = especialidad_nombre;
}

double Medico::get_pagos_por_atencion() const {
    return pagosPorAtencion;
}

void Medico::set_pagos_por_atencion(const double pagos_por_atencion) {
    pagosPorAtencion = pagos_por_atencion;
}

void Medico::leer(ifstream &input) {
    input >> codigo;
    input.get();
    getline(input, nombre, ',');
    input >> tarifa;
}

bool Medico::operator<(const class Medico &other) const {
    return this->especialidadNombre<other.especialidadNombre or (this->especialidadNombre==other.especialidadNombre
            and this->nombre < other.nombre);
}

void Medico::guardarAtencion(const Atencion &a) {
    atenciones.push_back(a);
    pagosPorAtencion += tarifa*a.get_duracion().get_segundos()/3600.0;
}

void Medico::imprimir(ofstream &output) const {
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<"MEDICO:"<<endl;
    output<<"CODIGO:  "<<codigo<<endl; output<<"NOMBRE:  "<<nombre<<endl;
    output<<"ESPECIALIDAD: "<<especialidadNombre<<endl; output<<"TARIFA:    "<<tarifa<<endl;
    output<<"ATENCIONES:"<<endl;
    output<<left<<setw(12)<<"FECHA"<<setw(10)<<"MEDICO"<<setw(12)<<"INICIO"<<setw(12)<<"ALTA"<<setw(12)<<"DURACION"
          <<setw(14)<<"F. CARDIACA"<<setw(10)<<"P. SIST."<<setw(10)<<"P. DIAST."<<setw(14)<<"TEMPERATURA"<<"SATURACION"<<right<<endl;

    for (int i=0; i<atenciones.size(); i++) {
        output << atenciones.at(i);
    }

    output<<"INGRESOS POR ATENCIONES:  "<<pagosPorAtencion<<endl;
}

Medico::Medico() {
    codigo = 0;
    tarifa = 0;
    pagosPorAtencion = 0;
}

Medico::~Medico() {
    atenciones.clear();
}

void operator>>(ifstream &input, class Medico &m) {
    m.leer(input);
}

void operator<<(ofstream &output, const class Medico &m) {
    m.imprimir(output);
}
