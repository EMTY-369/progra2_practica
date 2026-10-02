//
// Created by User on 1/10/2026.
//

#ifndef INC_2025_1_BIBLIOTECAGENERICA_HPP
#define INC_2025_1_BIBLIOTECAGENERICA_HPP
#include "Helpers.hpp"

void crea_lista(void *&lista, void* (* lee)(ifstream &), void* (* clasifica)(void**, const void*), const char *file_name);
void imprime_lista(const void *lista, void (*imprime)(ofstream &, const void *), const char *file_name);
void genera_lista(void *&lista);
void insertar_lista(void *&lista, void *dato, void* (* clasifica)(void**, const void*));

#endif //INC_2025_1_BIBLIOTECAGENERICA_HPP
