//
// Created by alois on 28/10/26.
//

#include "Empresa.hpp"

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(const int dni) {
    this->dni = dni;
}

void Empresa::get_nombre(char *nombre) {
    if (this->nombre == nullptr) nombre[0] = 0;
    else strcpy(nombre, this->nombre);
}

void Empresa::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(const int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(const int num_multas) {
    numMultas = num_multas;
}

void Empresa::get_placaI(char *placa, int i) {
    if (placas[i] == nullptr) placa[0] = 0;
    else strcpy(placa, placas[i]);
}

void Empresa::set_placaI(const char *placa, int i) {
    if (placas[i] != nullptr) delete[] placas[i];
    placas[i] = Utils::asignar_cadena(placa);
}

void Empresa::leer(ifstream &input) {
    int num;
    input >> num;
    if (input.eof()) return;
    input.get();
    set_dni(num);
    nombre = Utils::leer_cadena(input, ',');

    while (true) {
        char placa[9]{};
        input.get(placa, 9);
        placas[numPlacas++] = Utils::asignar_cadena(placa);
        if (input.get()=='\r') break;
    }
}

void Empresa::imprimir_multas(ofstream &output) {
    output<<setw(10)<<""<<left<<setw(14)<<"Placa"<<setw(26)<<"Fecha de infraccion"<<setw(24)<<"Codigo de infraccion";
    output<<setw(12)<<"Multa"<<"Fecha de pago"<<endl;
    for (int i=0; i<numMultas; i++) {
        output<<setw(10)<<"";
        output<<multas[i];
    }
}

Empresa::Empresa() {
    dni=0;
    nombre = nullptr;
    for (int i=0; i<NUM_PLACAS; i++) {
        placas[i] = nullptr;
    }
    numPlacas = 0;
    numMultas = 0;
}

Empresa::~Empresa() {
    delete[] nombre;
    for (int i=0; i<NUM_PLACAS; i++) {
        delete[] placas[i];
    }
}

void Empresa::operator=(Empresa &e) {
    set_dni(e.get_dni());
    char nombre[50]{};
    e.get_nombre(nombre);
    set_nombre(nombre);

    for (int i=0; i<e.get_num_placas(); i++) {
        char placa[9]{};
        e.get_placaI(placa, i);
        set_placaI(placa,i);
    }
    set_num_placas(e.get_num_placas());
}

void Empresa::operator+=(const class Multa &m) {
    multas[numMultas++] = m;
}

void operator>>(ifstream &input, class Empresa &e) {
    e.leer(input);
}

void operator<<(ofstream &output, class Empresa &e) {
    char nombre[MAX_CADENA]{};
    e.get_nombre(nombre);
    output<<left<<setw(14)<<e.get_dni()<<setw(50)<<nombre;
    for (int i=0; i<e.get_num_placas(); i++) {
        char placa[9]{};
        e.get_placaI(placa, i);
        output<<setw(14)<<placa;
    }
    output<<endl<<right;
    e.imprimir_multas(output);
}
