//
// Created by alois on 22/9/26.
//

#ifndef INC_2025_1_FUNCIONES_HPP
#define INC_2025_1_FUNCIONES_HPP
#include "Utils.hpp"
#include "Tabla.hpp"

void inicializar_tabla(struct Tabla &t);
void insertar_columna(struct Tabla &t, void *col);
void incrementar_espacios(void ** &lista_col, int &cant_col, int &cap_col, int inc);
void *insertar_fila(struct Tabla &t);
void insertar_campo();

#endif //INC_2025_1_FUNCIONES_HPP
