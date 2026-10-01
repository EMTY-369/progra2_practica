//
// Created by User on 30/09/2026.
//

#ifndef INC_2026_1_BIBLIOTECAREGISTROS_HPP
#define INC_2026_1_BIBLIOTECAREGISTROS_HPP
#include "BibliotecaGenerica.hpp"
void* lee_registro(ifstream &input);
int compara_reg(const void *a,const void *b);
bool verifica_reg(const void*a, const void*b);
void imprime_registro(ofstream &output, const void *registro);
void imprimir_encabezado(ofstream & output);
#endif //INC_2026_1_BIBLIOTECAREGISTROS_HPP
