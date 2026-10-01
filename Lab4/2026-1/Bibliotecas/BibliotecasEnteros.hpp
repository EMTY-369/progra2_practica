//
// Created by User on 30/09/2026.
//

#ifndef INC_2026_1_BIBLIOTECASENTEROS_HPP
#define INC_2026_1_BIBLIOTECASENTEROS_HPP
#include "BibliotecaGenerica.hpp"
void *lee_num(ifstream &input);
int compara_num(const void *a, const void *b);
bool verifica_num(const void *dato1, const void *dato2);
void imprime_num(ofstream &output, const void *dato);
#endif //INC_2026_1_BIBLIOTECASENTEROS_HPP
