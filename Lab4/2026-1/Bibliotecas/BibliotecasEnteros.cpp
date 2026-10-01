//
// Created by User on 30/09/2026.
//

#include "BibliotecasEnteros.hpp"

void imprime_num(ofstream &output, const void *dato) {
    output<<*(int *) dato<<endl;
}

bool verifica_num(const void *dato1, const void *dato2) {
    int *ptr_int1 = (int *) dato1, *ptr_int2 = (int *) dato2;
    return *ptr_int1 > *ptr_int2;
}

int compara_num(const void *a, const void *b) {
    void *aux1 = *(void **) a, *aux2 = *(void **) b;
    int value1 = *(int *) aux1, value2 = *(int *) aux2;
    return value1 - value2;
}

void *lee_num(ifstream &input) {
    int dato;
    input>>dato;
    auto *ptr_int = new int;
    *ptr_int = dato;
    return ptr_int;
}
