//
// Created by alois on 29/10/26.
//

#include "Plato.hpp"

void Plato::get_codigo(char *codigo) {
    if (this->codigo==nullptr) codigo[0] = 0;
    else strcpy(codigo,this->codigo);
}

void Plato::set_codigo(const char *codigo) {
    if (this->codigo!=nullptr) delete[] this->codigo;
    this->codigo = Utils::asignar_cadena(codigo);
}

void Plato::get_nombre(char *nombre) {
    if (this->nombre==nullptr) nombre[0] = 0;
    else strcpy(nombre,this->nombre);
}

void Plato::set_nombre(const char *nombre) {
    if (this->nombre!=nullptr) delete[] this->nombre;
    this->nombre = Utils::asignar_cadena(nombre);
}

double Plato::get_precio() const {
    return precio;
}

void Plato::set_precio(const double precio) {
    this->precio = precio;
}

void Plato::get_categoria(char *categoria) {
    if (this->categoria==nullptr) categoria[0] = 0;
    else strcpy(categoria,this->categoria);
}

void Plato::set_categoria(const char *categoria) {
    if (this->categoria!=nullptr) delete[] this->categoria;
    this->categoria = Utils::asignar_cadena(categoria);
}

int Plato::get_preparados() const {
    return preparados;
}

void Plato::set_preparados(const int preparados) {
    this->preparados = preparados;
}

double Plato::get_descuento() const {
    return descuento;
}

void Plato::set_descuento(const double descuento) {
    this->descuento = descuento;
}

int Plato::get_atendidos() const {
    return atendidos;
}

void Plato::set_atendidos(const int atendidos) {
    this->atendidos = atendidos;
}

int Plato::get_no_atentidos() const {
    return noAtentidos;
}

void Plato::set_no_atentidos(const int no_atentidos) {
    noAtentidos = no_atentidos;
}

double Plato::get_total_esperado() const {
    return totalEsperado;
}

void Plato::set_total_esperado(const double total_esperado) {
    totalEsperado = total_esperado;
}

double Plato::get_total_bruto() const {
    return totalBruto;
}

void Plato::set_total_bruto(const double total_bruto) {
    totalBruto = total_bruto;
}

double Plato::get_tota_neto() const {
    return totalNeto;
}

void Plato::set_tota_neto(const double tota_neto) {
    totalNeto = tota_neto;
}

Plato::Plato() {
    codigo=nullptr;
    nombre=nullptr;
    precio=0;
    categoria=nullptr;
    preparados=0;
    descuento=0;
    atendidos=0;
    noAtentidos=0;
    totalEsperado=0;
    totalBruto=0;
    totalNeto=0;
}

Plato::Plato(const class Plato &other) {
    codigo=nullptr;
    nombre=nullptr;
    categoria=nullptr;
    *this=other;
}

Plato::~Plato() {
    delete[] this->codigo;
    delete[] this->nombre;
    delete[] this->categoria;
}

void Plato::operator=(const class Plato &other) {
    if (other.codigo!=nullptr) set_codigo(other.codigo);
    else codigo=nullptr;

    if (other.nombre!=nullptr) set_nombre(other.nombre);
    else nombre=nullptr;

    set_precio(other.precio);

    if (other.categoria!=nullptr) set_categoria(other.categoria);
    else categoria=nullptr;

    set_preparados(other.preparados);
    set_descuento(other.descuento);
    set_atendidos(other.atendidos);
    set_no_atentidos(other.noAtentidos);
    set_total_esperado(other.totalEsperado);
    set_total_bruto(other.totalBruto);
    set_tota_neto(other.totalNeto);
}

void Plato::leer(ifstream &input) {
    //AP31796,ANTICUCHO DE CORAZON AL PLATO,31.90,APERITIVO,43,19.94%
    char buffer[9]{};
    input.getline(buffer,9, ',');
    if (input.eof()) return;
    set_codigo(buffer);
    nombre = Utils::leer_cadena(input, ',');
    input>>precio;
    input.get();
    categoria = Utils::leer_cadena(input, ',');
    input>>preparados;
    totalEsperado+=preparados*precio;
    if (input.get()==',') {
        input>>descuento;
        input.get();
    }
    input>>ws;
}

double Plato::actualizar(int cant, double desct_c) {
    double costo=0;
    if (preparados>=atendidos+cant) {
        atendidos+=cant;
        totalBruto+=cant*precio;
        costo=cant*precio*((100-descuento)/100.0)*((100-desct_c)/100.0);
    } else {
        if (preparados!=atendidos) {
            cant -= preparados-atendidos;
            totalBruto+=(preparados-atendidos)*precio;
            costo=(preparados-atendidos)*precio*((100-descuento)/100.0)*((100-desct_c)/100.0);
            atendidos=preparados;
        }
        noAtentidos+=cant;
    }
    totalNeto+=costo;
    return costo;
}

void Plato::imprimir(ofstream &output) const {
    output<<left<<setw(12)<<codigo<<setw(45)<<nombre<<right;
    output<<setw(6)<<precio<<setw(4)<<""<<left<<setw(14)<<categoria;
    output<<right<<setw(6)<<descuento<<"%"<<setw(10)<<preparados;
    output<<setw(10)<<atendidos<<setw(10)<<noAtentidos;
    output<<setw(15)<<totalEsperado<<setw(15)<<totalBruto<<setw(15)<<totalNeto<<endl;
}

void operator>>(ifstream &input, class Plato &p) {
    p.leer(input);
}

void operator<<(ofstream &output, const class Plato &p) {
    p.imprimir(output);
}
