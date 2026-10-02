//
// Created by User on 1/10/2026.
//

#ifndef INC_2025_1_BIBLIOTECAENTEROS_HPP
#define INC_2025_1_BIBLIOTECAENTEROS_HPP
#include "BibliotecaGenerica.hpp"

void *lee_num(ifstream &input);
void *clasifica_entero(void **listaTAD, const void *dato);
void imprime_num(ofstream &output, const void *dato);

#endif //INC_2025_1_BIBLIOTECAENTEROS_HPP
