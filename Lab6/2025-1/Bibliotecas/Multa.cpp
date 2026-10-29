//
// Created by alois on 28/10/26.
//

#include "Multa.hpp"

void Multa::get_placa(char *placa) {
    if (this->placa==nullptr) placa[0]=0;
    else strcpy(placa,this->placa);
}

void Multa::set_placa(const char *placa) {
    if (this->placa!=nullptr) delete[] this->placa;
    this->placa=Utils::asignar_cadena(placa);
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(const int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(const int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(const int codigo_ifraccion) {
    codigoInfraccion = codigo_ifraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(const double multa) {
    this->multa = multa;
}

Multa::Multa() {
    placa = nullptr;
    fechaDeInfraccion = 0;
    fechaDePago = 0;
    codigoInfraccion = 0;
    multa = 0;
}

Multa::Multa(const class Multa &other) {
    placa = nullptr;
    *this = other;
}

Multa::~Multa() {
    delete[] placa;
}

void Multa::operator=(const class Multa &other) {
    if (other.placa != nullptr) set_placa(other.placa);
    else placa = nullptr;
    set_fecha_de_infraccion(other.fechaDeInfraccion);
    set_fecha_de_pago(other.fechaDePago);
    set_codigo_infraccion(other.codigoInfraccion);
    set_multa(other.multa);
}

void operator>>(ifstream &input, class Multa &m) {
    m.leer(input);
}

void operator<<(ofstream &output, class Multa &m) {
    char placa[9]{};
    m.get_placa(placa);
    output<<left<<setw(18)<<placa<<right;
    Utils::imprimir_fecha(output, m.get_fecha_de_infraccion());
    output<<setw(20)<<"";
    output<<left<<setw(16)<<m.get_codigo_infraccion()<<setw(14)<<m.get_multa()<<right;
    Utils::imprimir_fecha(output, m.get_fecha_de_pago());
    output<<endl;
}

void Multa::leer(ifstream &input) {
    int dd, mm, aa;
    char c;
    input>>dd;
    if (input.eof()) return;
    input>>c>>mm>>c>>aa>>c;
    fechaDeInfraccion = aa*10000 + mm*100 + dd;
    placa = Utils::leer_cadena(input, ',');
    input>>codigoInfraccion;
    if (input.get()==',') {
        input>>c>>c>>dd>>c>>mm>>c>>aa;
        fechaDePago = aa*10000 + mm*100 + dd;
    }
}
