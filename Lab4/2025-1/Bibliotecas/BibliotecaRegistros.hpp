//
// Created by User on 1/10/2026.
//

#ifndef INC_2025_1_BIBLIOTECAREGISTROS_HPP
#define INC_2025_1_BIBLIOTECAREGISTROS_HPP
#include "BibliotecaGenerica.hpp"

void *lee_registro(ifstream &input);
void *clasifica_resgistro(void **listaTAD, const void *dato);
void imprime_registro(ofstream &output, const void *dato);
void imprimir_encabezado(ofstream &output);

#endif //INC_2025_1_BIBLIOTECAREGISTROS_HPP
