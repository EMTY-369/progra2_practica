//
// Created by User on 19/11/2026.
//

#include "Triaje.hpp"


string Triaje::get_codigo_triaje() const {
    return codigoTriaje;
}

void Triaje::set_codigo_triaje(const string &codigo_triaje) {
    codigoTriaje = codigo_triaje;
}

string Triaje::get_codigo_paciente() const {
    return codigoPaciente;
}

void Triaje::set_codigo_paciente(const string &codigo_paciente) {
    codigoPaciente = codigo_paciente;
}

int Triaje::get_frecuencia_cardiaca() const {
    return frecuenciaCardiaca;
}

void Triaje::set_frecuencia_cardiaca(const int frecuencia_cardiaca) {
    frecuenciaCardiaca = frecuencia_cardiaca;
}

int Triaje::get_presion_sistolica() const {
    return presionSistolica;
}

void Triaje::set_presion_sistolica(const int presion_sistolica) {
    presionSistolica = presion_sistolica;
}

int Triaje::get_presion_diastolica() const {
    return presionDiastolica;
}

void Triaje::set_presion_diastolica(const int presion_diastolica) {
    presionDiastolica = presion_diastolica;
}

double Triaje::get_temperatura() const {
    return temperatura;
}

void Triaje::set_temperatura(const double temperatura) {
    this->temperatura = temperatura;
}

int Triaje::get_saturacion_de_oxigeno() const {
    return saturacionDeOxigeno;
}

void Triaje::set_saturacion_de_oxigeno(const int saturacion_de_oxigeno) {
    saturacionDeOxigeno = saturacion_de_oxigeno;
}

void Triaje::leer(ifstream &input) {
    string cod;
    getline(input, cod, ',');
    if (input.eof()) return;
    codigoTriaje = cod;
    getline(input,codigoPaciente, ',');
    input>>frecuenciaCardiaca;
    input.get();
    input>>presionSistolica;
    input.get();
    input>>presionDiastolica;
    input.get();
    input>>temperatura;
    input.get();
    input>>saturacionDeOxigeno;
    input.get();
}

void Triaje::imprimir(ofstream &output) const {
    output<<setw(12)<<frecuenciaCardiaca<<setw(10)<<presionSistolica<<setw(10)<<presionDiastolica<<setw(10)<<temperatura<<setw(12)<<saturacionDeOxigeno<<endl;
}

Triaje::Triaje() {
    frecuenciaCardiaca = 0;
    presionSistolica = 0;
    presionDiastolica = 0;
    temperatura = 0;
    saturacionDeOxigeno = 0;
}

Triaje::Triaje(const class Triaje &other) {
    frecuenciaCardiaca = 0;
    presionSistolica = 0;
    presionDiastolica = 0;
    temperatura = 0;
    saturacionDeOxigeno = 0;
    *this = other;
}

void operator>>(ifstream &input, class Triaje &t) {
    t.leer(input);
}

void operator<<(ofstream &output, const class Triaje &t) {
    t.imprimir(output);
}
