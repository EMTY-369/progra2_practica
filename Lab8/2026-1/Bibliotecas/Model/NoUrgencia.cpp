//
// Created by User on 11/11/2026.
//

#include "NoUrgencia.hpp"

string NoUrgencia::get_especialidad() const {
    return especialidad;
}

void NoUrgencia::set_especialidad(const string &especialidad) {
    this->especialidad = especialidad;
}

bool NoUrgencia::is_es_consulta_programada() const {
    return es_consulta_programada;
}

void NoUrgencia::set_es_consulta_programada(const bool es_consulta_programada) {
    this->es_consulta_programada = es_consulta_programada;
}

int NoUrgencia::obtener_prioridad() {
    return 3;
}

int NoUrgencia::obtener_llave() {
    return 3*10000+get_codigo();
}

NoUrgencia * NoUrgencia::clonar() const {
    return new NoUrgencia(*this);
}

void NoUrgencia::leer(ifstream &input, int hora) {
    Atencion::leer(input, hora);

    getline(input, especialidad, ',');
    input>>es_consulta_programada;
    input.get();
}

void NoUrgencia::imprimir(ofstream &output) {
    Atencion::imprimir(output);

    output<<setw(30)<<especialidad;
    if (es_consulta_programada) output<<setw(20)<<"SI";
    else output<<setw(20)<<"NO";
    output<<endl;
}

NoUrgencia::NoUrgencia() {
    es_consulta_programada = false;
}

NoUrgencia::NoUrgencia(const class NoUrgencia &other) {
    es_consulta_programada = false;
    *this = other;
}

NoUrgencia::~NoUrgencia() {
    cout << "Destruyendo NoUrgencia" << endl;
}
