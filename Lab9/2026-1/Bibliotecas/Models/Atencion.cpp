//
// Created by User on 19/11/2026.
//

#include "Atencion.hpp"

int Atencion::get_codigo_medico() const {
    return codigoMedico;
}

void Atencion::set_codigo_medico(const int codigo_medico) {
    codigoMedico = codigo_medico;
}

string Atencion::get_codigo_triaje() const {
    return codigoTriaje;
}

void Atencion::set_codigo_triaje(const string &codigo_triaje) {
    codigoTriaje = codigo_triaje;
}

class Hora Atencion::get_duracion() const {
    return duracion;
}

void Atencion::set_duracion(const class Hora &duracion) {
    this->duracion = duracion;
}

class Triaje Atencion::get_triaje() const {
    return triaje;
}

void Atencion::set_triaje(const class Triaje &triaje) {
    this->triaje = triaje;
}

int Atencion::get_fecha() const {
    return fecha;
}

void Atencion::set_fecha(const int fecha) {
    this->fecha = fecha;
}

string Atencion::get_codigo_paciente() const {
    return codigoPaciente;
}

void Atencion::set_codigo_paciente(const string &codigo_paciente) {
    codigoPaciente = codigo_paciente;
}

class Hora Atencion::get_hora_ingreso() const {
    return horaIngreso;
}

void Atencion::set_hora_ingreso(const class Hora &hora_ingreso) {
    horaIngreso = hora_ingreso;
}

class Hora Atencion::get_hora_alta() const {
    return horaAlta;
}

void Atencion::set_hora_alta(const class Hora &hora_alta) {
    horaAlta = hora_alta;
}

void Atencion::leer(ifstream &input) {
    input >> horaIngreso;
    getline(input,codigoPaciente,',');
    input >> horaAlta;
    input >> codigoMedico;
    input.get();
    char buffer[7];
    input >> buffer;
    codigoTriaje = buffer;
}

bool Atencion::operator<(const class Atencion &other) const {
    return this->fecha<other.fecha or (this->fecha == other.fecha and
           this->codigoTriaje < other.codigoTriaje);
}

void Atencion::calcularDuracion() {
    duracion.set_segundos(horaAlta.get_segundos() - horaIngreso.get_segundos());
    int tiempo = duracion.get_segundos();
    duracion.set_hh(tiempo/3600);
    tiempo = tiempo%3600;
    duracion.set_mm(tiempo/60);
    duracion.set_ss(tiempo%60);
}

void Atencion::imprimir(ofstream &output) const {
    Utils::imprimir_fecha(output, fecha);
    output<<setw(8)<<codigoMedico<<setw(4)<<"";
    output<<horaIngreso;
    output<<setw(4)<<"";
    output<<horaAlta;
    output<<setw(4)<<"";
    output<<duracion;
    output<<triaje;
}

Atencion::Atencion() {
    fecha = 0;
    codigoMedico = 0;
}

void operator>>(ifstream &input, class Atencion &a) {
    a.leer(input);
}

void operator<<(ofstream &output,const class Atencion &a) {
    a.imprimir(output);
}
