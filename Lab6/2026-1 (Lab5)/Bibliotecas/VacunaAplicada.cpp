//
// Created by alois on 27/10/26.
//

#include "VacunaAplicada.hpp"

void VacunaAplicada::get_nombre(char *nombre) const {
    if (this->nombre == nullptr) nombre[0] = '\0';
    else strcpy(nombre, this->nombre);
}

void VacunaAplicada::set_nombre(const char *nombre) {
    if (this->nombre != nullptr) delete[] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

int VacunaAplicada::get_fecha() const {
    return fecha;
}

void VacunaAplicada::set_fecha(const int fecha) {
    this->fecha = fecha;
}

double VacunaAplicada::get_dosis() const {
    return dosis;
}

void VacunaAplicada::set_dosis(const double dosis) {
    this->dosis = dosis;
}

void VacunaAplicada::get_colegiatura(char *colegiatura) const {
    if (this->colegiatura == nullptr) colegiatura[0] = '\0';
    else strcpy(colegiatura, this->colegiatura);
}

void VacunaAplicada::set_colegiatura(const char *colegiatura) {
    if (this->colegiatura != nullptr) delete[] this->colegiatura;
    this->colegiatura = Utils::asignar_cadena(colegiatura);
}

VacunaAplicada::VacunaAplicada() {
    nombre = nullptr;
    fecha = 0;
    dosis = 0;
    colegiatura = nullptr;
}

VacunaAplicada::VacunaAplicada(const VacunaAplicada &other) {
    nombre = nullptr;
    colegiatura = nullptr;
    *this = other;
}

VacunaAplicada::~VacunaAplicada() {
    delete []nombre;
    delete []colegiatura;
}

void VacunaAplicada::operator=(const VacunaAplicada &other) {
    if (other.nombre != nullptr) set_nombre(other.nombre);
    else nombre = nullptr;
    set_fecha(other.fecha);
    set_dosis(other.dosis);
    if (other.colegiatura != nullptr) set_colegiatura(other.colegiatura);
    else colegiatura = nullptr;
}

bool VacunaAplicada::operator==(const VacunaAplicada &other) {
    return (strcmp(nombre, other.nombre) == 0 and dosis == other.dosis and
            fecha == other.fecha and strcmp(colegiatura, other.colegiatura) == 0);
}

void operator>>(ifstream &input, class VacunaAplicada &v) {
    v.leer(input);
}

void operator<<(ofstream &output, const VacunaAplicada &v) {
    char nombre[40]{}, colegiatura[40]{};
    v.get_nombre(nombre);
    v.get_colegiatura(colegiatura);
    output<<" - "<<nombre<<" : ";
    Utils::imprimir_fecha(output,v.get_fecha());
    output<<" ("<<v.get_dosis()<<" ml, "<<colegiatura<<")"<<endl;
}

void VacunaAplicada::leer(ifstream &input) {
    //Rabia,20250110,1.5,CMVP-100
    nombre = Utils::leer_cadena(input, ',');
    input>>fecha;
    input.get();
    input>>dosis;
    input.get();
    colegiatura = Utils::leer_cadena(input, '\n');
}
