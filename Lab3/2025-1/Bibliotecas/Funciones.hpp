//
// Created by alois on 22/9/26.
//

#ifndef INC_2025_1_FUNCIONES_HPP
#define INC_2025_1_FUNCIONES_HPP
#include "Utils.hpp"
#include "Tabla.hpp"

void inicializar_tabla(struct Tabla &t);
void insertar_columna(struct Tabla &t, void *col);
void incrementar_espacios(void ** &lista, int &cant, int &cap, int inc);
void *insertar_fila(struct Tabla &t);
void insertar_campo(struct Tabla &t, void * fila, int num_campo, void * dato);
void cargar_tabla_infracciones(struct Tabla & t, const char *file_name);
void leer_infracciones(struct Tabla & t, const char * file_name);
void abrir_archivo_lectura(ifstream &input, const char *file_name);
void * leer_registro(ifstream & input);
char * asignar_cadena(char *buffer);
void *abrir_cursor(const struct Tabla &t);
bool hay_siguiente(void *&cursor);
void *obtener_campo(void *& cursor, int num_campo);
void recorrer_tabla(const struct Tabla &t);

#endif //INC_2025_1_FUNCIONES_HPP
