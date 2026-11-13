//
// Created by User on 12/11/2026.
//

#include "NodoABB.hpp"

NodoABB::NodoABB() {
    metrica = nullptr;
    izq = nullptr;
    der = nullptr;
}

NodoABB::NodoABB( Metrica *tipo, NodoABB *izq, NodoABB *der) {
    metrica = tipo;
    this->izq = izq;
    this->der = der;
}

NodoABB::~NodoABB() {
    delete metrica;
}
