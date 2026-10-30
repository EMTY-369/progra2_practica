//
// Created by alois on 29/10/26.
//

#include "Cliente.hpp"

int Cliente::get_dni() const {
    return dni;
}

void Cliente::set_dni(const int dni) {
    this->dni = dni;
}

void Cliente::get_nombre(char *nombre) {
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Cliente::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

void Cliente::get_distrito(char *distrito) {
    if (this->distrito == nullptr) distrito[0] = 0;
    else strcpy(distrito, this->distrito);
}

void Cliente::set_distrito(const char *distrito) {
    if (this->distrito != nullptr) delete[] this->distrito;
    this->distrito = Utils::asignar_cadena(distrito);
}

double Cliente::get_descuento() const {
    return descuento;
}

void Cliente::set_descuento(const double descuento) {
    this->descuento = descuento;
}

double Cliente::get_total_pagado() const {
    return totalPagado;
}

void Cliente::set_total_pagado(const double total_pagado) {
    totalPagado = total_pagado;
}

Cliente::Cliente() {
    dni = 0;
    nombre = nullptr;
    distrito = nullptr;
    descuento = 0;
    totalPagado = 0;
}

Cliente::Cliente(const class Cliente &cliente) {
    nombre = nullptr;
    distrito = nullptr;
    *this=cliente;
}

Cliente::~Cliente() {
    delete[] nombre;
    delete[] distrito;
}

void Cliente::operator=(const class Cliente &other) {
    set_dni(other.dni);
    if (other.nombre != nullptr) set_nombre(other.nombre);
    else nombre = nullptr;
    if (other.distrito != nullptr) set_distrito(other.distrito);
    else distrito = nullptr;
    set_descuento(other.descuento);
    set_total_pagado(other.totalPagado);
}

void Cliente::leer(ifstream &input) {
    //90367684,CORONEL CHUMPITAZ HELI,Villa Maria del Triunfo,S,13.04%
    int num;
    input >> num;
    if (input.eof()) return;
    input.get();
    set_dni(num);
    nombre = Utils::leer_cadena(input, ',');
    distrito = Utils::leer_cadena(input, ',');
    if (input.get()=='S') {
        input.get();
        input >> descuento;
        input.get();
    }
}

void Cliente::actualizar(double gasto) {
    totalPagado+=gasto;
}

void Cliente::imprimir(ofstream &output) const {
    output<<dni<<setw(6)<<""<<left<<setw(40)<<nombre<<setw(35)<<distrito;
    output<<right<<setw(10)<<descuento<<"%"<<setw(14)<<totalPagado<<endl;
}

void operator>>(ifstream &input, class Cliente &c) {
    c.leer(input);
}

void operator<<(ofstream &output,const class Cliente &c) {
    c.imprimir(output);
}
