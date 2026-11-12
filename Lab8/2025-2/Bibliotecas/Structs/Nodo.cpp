//
// Created by User on 12/11/2026.
//

#include "Nodo.hpp"

Nodo::Nodo() {
    metrica = nullptr;
    anterior = nullptr;
    siguiente = nullptr;
}

Nodo::Nodo(class Metrica *tipo, class Nodo *anterior, class Nodo *siguiente) {
    metrica = tipo;
    this->anterior = anterior;
    this->siguiente = siguiente;
}

Nodo::~Nodo() {
    delete metrica;
}

