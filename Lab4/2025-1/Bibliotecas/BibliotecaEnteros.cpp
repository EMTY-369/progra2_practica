//
// Created by User on 1/10/2026.
//

#include "BibliotecaEnteros.hpp"

void imprime_num(ofstream &output, const void *dato) {
    int num = *(int*)dato;
    output << num << endl;
}

void *clasifica_entero(void **listaTAD, const void *dato) {
    int num = *(int*)dato;
    if (num < COMPARAR_INT) return listaTAD[INICIO1];
    else return listaTAD[INICIO2];
}

void *lee_num(ifstream &input) {
    int num;
    input >> num;
    if (input.eof()) return nullptr;
    auto *ptr_num = new int(num);
    return ptr_num;
}