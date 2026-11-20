//
// Created by User on 19/11/2026.
//

#include "Paciente.hpp"

string Paciente::get_codigo() const {
    return codigo;
}

void Paciente::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

string Paciente::get_nombre() const {
    return nombre;
}

void Paciente::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

char Paciente::get_sexo() const {
    return sexo;
}

void Paciente::set_sexo(const char sexo) {
    this->sexo = sexo;
}

int Paciente::get_edad() const {
    return edad;
}

void Paciente::set_edad(const int edad) {
    this->edad = edad;
}

double Paciente::get_gastos_por_atencion() const {
    return gastosPorAtencion;
}

void Paciente::set_gastos_por_atencion(const double gastos_por_atencion) {
    gastosPorAtencion = gastos_por_atencion;
}

void Paciente::leer(ifstream &input) {
    string cod;
    getline(input, cod, ',');
    if (input.eof()) return;
    codigo = cod;
    getline(input, nombre, ',');
    input>>sexo;
    input.get();
    input>>edad;
    input.get();
}

bool Paciente::operator<(const class Paciente &other) const {
    return this->nombre<other.nombre;
}

void Paciente::guardarAtencion(const Atencion &a, double tarifa) {
    atenciones.push_back(a);
    gastosPorAtencion += tarifa*a.get_duracion().get_segundos()/3600.0;
}

void Paciente::imprimir(ofstream &output) const {
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<"PACIENTE:"<<endl;
    output<<"CODIGO:  "<<codigo<<endl; output<<"NOMBRE:  "<<nombre<<endl;
    output<<"Sexo:    "<<sexo<<endl; output<<"EDAD:    "<<edad<<endl;
    output<<"ATENCIONES:"<<endl;
    output<<left<<setw(12)<<"FECHA"<<setw(10)<<"MEDICO"<<setw(12)<<"INICIO"<<setw(12)<<"ALTA"<<setw(12)<<"DURACION"
          <<setw(14)<<"F. CARDIACA"<<setw(10)<<"P. SIST."<<setw(10)<<"P. DIAST."<<setw(14)<<"TEMPERATURA"<<"SATURACION"<<right<<endl;

    auto it = atenciones.begin();
    for (int i=0; i<atenciones.size(); i++) {
        output << *it;
        ++it;
    }

    output<<"COSTO POR ATENCIONES:  "<<gastosPorAtencion<<endl;
}

Paciente::Paciente() {
    sexo = 0;
    edad = 0;
    gastosPorAtencion = 0;
}

Paciente::~Paciente() {
    atenciones.clear();
}

void operator>>(ifstream &input, class Paciente &p) {
    p.leer(input);
}

void operator<<(ofstream &output, const class Paciente &p) {
    p.imprimir(output);
}
