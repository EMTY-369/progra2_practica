//
// Created by User on 30/09/2026.
//

#ifndef INC_2026_1_BIBLIOTECAGENERICA_HPP
#define INC_2026_1_BIBLIOTECAGENERICA_HPP
#include "Helpers.hpp"

void procesa_arreglo(void **arr, void*(* lee)(ifstream &), const char *file_name);
void crea_lista(void **arr,void *&lista, int (* cmp)(const void *,const void *) );
void genera_lista(void *&lista);
void inserta_lista(void *&lista, void **arr);
void fusiona_listas(void *&lista1, void *lista2, bool(* verifica)(const void*, const void*));
void imprime_lista(const void *lista, void(* imprime)(ofstream &, const void *), const char *file_name);

#endif //INC_2026_1_BIBLIOTECAGENERICA_HPP
