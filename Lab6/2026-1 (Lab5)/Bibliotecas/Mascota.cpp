//
// Created by alois on 27/10/26.
//

#include "Mascota.hpp"

int Mascota::get_dni() const {
    return dni;
}

void Mascota::set_dni(const int dni) {
    this->dni = dni;
}

void Mascota::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void Mascota::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

void Mascota::get_especie(char *especie) const {
    if (this->especie == nullptr) especie[0] = '\0';
    else strcpy(especie, this->especie);
}

void Mascota::set_especie(const char *especie) {
    if (this->especie != nullptr) delete[] this->especie;
    this->especie = Utils::asignar_cadena(especie);
}

int Mascota::get_edad() const {
    return edad;
}

void Mascota::set_edad(const int edad) {
    this->edad = edad;
}

double Mascota::get_peso() const {
    return peso;
}

void Mascota::set_peso(const double peso) {
    this->peso = peso;
}

void Mascota::get_colegiatura(char *colegiatura) const {
    if (this->colegiatura == nullptr) colegiatura[0] = '\0';
    else strcpy(colegiatura, this->colegiatura);
}

void Mascota::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura != nullptr) delete[] this->colegiatura;
    this->colegiatura = Utils::asignar_cadena(colegiatura);
}

int Mascota::get_num_vacunas() const {
    return numVacunas;
}

void Mascota::set_num_vacunas(const int num_vacunas) {
    numVacunas = num_vacunas;
}

Mascota::Mascota() {
    dni = 0;
    nombre =  nullptr;
    especie = nullptr;
    edad = 0;
    peso = 0;
    colegiatura = nullptr;
    numVacunas = 0;
}

Mascota::Mascota(const Mascota &other) {
    *this = other;
}

Mascota::~Mascota() {
    delete[] nombre;
    delete[] especie;
    delete[] colegiatura;
}

void Mascota::operator=(const Mascota &other) {
    set_dni(other.dni);
    if (other.nombre!=nullptr) set_nombre(other.nombre);
    else nombre = nullptr;
    if (other.especie != nullptr) set_especie(other.especie);
    else especie = nullptr;
    set_edad(other.edad);
    set_peso(other.peso);
    if (other.colegiatura!=nullptr) set_colegiatura(other.colegiatura);
    else colegiatura =  nullptr;
    set_num_vacunas(other.numVacunas);
}

void operator>>(ifstream &input, class Mascota &m) {
    m.leer(input);
}

void operator<<(ofstream &output,const class Mascota &m) {
    char nombre[40]{}, especie[40]{};
    m.get_nombre(nombre);
    m.get_especie(especie);
    output<<"Mascota : "<<nombre<<" ("<<especie<<", "<<m.get_edad()<<" años, "<<m.get_peso()<<" kg)"<<endl;

}

void Mascota::leer(ifstream &input) {
    //11223344,Michi,Gato,4,5.1,CMVP-6002
    int num;
    input>>num;
    if (input.eof()) return;
    input.get();
    dni = num;
    nombre = Utils::leer_cadena(input, ',');
    especie = Utils::leer_cadena(input, ',');
    input >> edad;
    input.get();
    input>>peso;
    input.get();
    colegiatura = Utils::leer_cadena(input, '\n');
}

void Mascota::imprimir_vacunas(ofstream &output) {
    if (numVacunas==0) return;
    if (~(*this)) output<<"**ALERTA: cartilla con registros duplicados**"<<endl;
    output<<"Vacunas:"<<endl;
    for (int i = 0; i < numVacunas; i++) {
        output << listaVacunas[i];
    }
    output << endl;
}

void Mascota::operator+=(class VacunaAplicada &v) {
    listaVacunas[numVacunas++] = v;
}

bool Mascota::operator~() {
    bool duplicado = false;
    for (int i = 0; i < numVacunas-1; i++) {
        if (listaVacunas[i]==listaVacunas[i+1]) duplicado = true;
    }
    return duplicado;
}

