//
// Created by User on 4/11/2026.
//

#include "Control.hpp"

double Control::get_costo() const {
    return costo;
}

void Control::set_costo(const double costo) {
    this->costo = costo;
}

int Control::get_codmed() const {
    return codmed;
}

void Control::set_codmed(const int codmed) {
    this->codmed = codmed;
}

void Control::leer(ifstream &input) {
    Cita::leer(input);
    input >> codmed;
    input.get();
    input >> costo;
}

void Control::imprimir(ofstream &output) {
    Cita::imprimir(output);
    output<<setw(10)<<codmed<<setw(10)<<costo<<endl;
}

int Control::comparar(const void *a, const void *b) {
    class Control *m1 = *(Control **) a;
    class Control *m2 = *(Control **) b;

    return m1->get_amascota().get_nombre().compare(m2->get_amascota().get_nombre());
}

Control::Control() {
    costo = 0;
    codmed = 0;
}

Control::Control(const class Control &origin) {
    *this = origin;
}
