//
// Created by alois on 28/10/26.
//

#include "Infraccion.hpp"

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const int codigo) {
    this->codigo = codigo;
}

void Infraccion::get_descripcion(char *descripcion) {
    if (this->descripcion == nullptr) descripcion[0] = 0;
    else strcpy(descripcion, this->descripcion);
}

void Infraccion::set_descripcion(const char *descripcion) {
    if (this->descripcion != nullptr) delete[] this->descripcion;
    this->descripcion = Utils::asignar_cadena(descripcion);
}

void Infraccion::get_gravedad(char *gravedad) {
    if (this->gravedad == nullptr) gravedad[0] = 0;
    else strcpy(gravedad, this->gravedad);
}

void Infraccion::set_gravedad(const char *gravedad) {
    if (this->gravedad != nullptr) delete[] this->gravedad;
    this->gravedad = Utils::asignar_cadena(gravedad);
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(const double multa) {
    this->multa = multa;
}

Infraccion::Infraccion() {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0;
}

Infraccion::Infraccion(const class Infraccion &other) {
    descripcion = nullptr;
    gravedad = nullptr;
    *this = other;
}

Infraccion::~Infraccion() {
    delete[] descripcion;
    delete[] gravedad;
}

void Infraccion::operator=(const class Infraccion &other) {
    set_codigo(other.codigo);
    if (other.descripcion != nullptr) set_descripcion(other.descripcion);
    else descripcion = nullptr;
    if (other.gravedad != nullptr) set_gravedad(other.gravedad);
    else gravedad = nullptr;
    set_multa(other.multa);
}

void Infraccion::leer(ifstream &input) {
    int cod;

    input>>cod;
    if (input.eof()) return;
    input.get();
    set_codigo(cod);
    input>>multa;
    input.get();
    gravedad = Utils::leer_cadena(input, ',');
    descripcion = Utils::leer_cadena(input, '\r'); //es funciona para linux, cambiar a \n papra windows
    input.get(); //eliminar esto para windows
}

void operator>>(ifstream &input,class Infraccion &i) {
    i.leer(input);
}

void operator<<(ofstream &output, class Infraccion &i) {
    char gravedad[50]{}, descripcion[MAX_CADENA]{};
    i.get_gravedad(gravedad);
    i.get_descripcion(descripcion);
    output<<left<<setw(10)<<i.get_codigo()<<setw(10)<<i.get_multa()<<setw(6)<<""
          <<setw(14)<<gravedad<<descripcion<<endl<<right;
}
