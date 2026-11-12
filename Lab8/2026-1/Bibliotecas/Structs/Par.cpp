//
// Created by User on 11/11/2026.
//

#include "Par.hpp"

class Atencion * Par::get_value() const {
    return value;
}

void Par::set_value(class Atencion *value) {
    this->value = value;
}

int Par::get_llave() const {
    return llave;
}

void Par::set_llave(const int llave) {
    this->llave = llave;
}

void Par::imprimir(ofstream &output) {
    output<<setw(12)<<llave;
    value->imprimir(output);
}

Par::Par() {
    llave = 0;
    value = nullptr;
}

Par::~Par() {
    delete value;
}
