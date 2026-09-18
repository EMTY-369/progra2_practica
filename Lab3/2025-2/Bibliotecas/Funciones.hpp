//
// Created by User on 17/09/2026.
//

#ifndef INC_2025_2_FUNCIONES_HPP
#define INC_2025_2_FUNCIONES_HPP
#include "Utils.hpp"

void cargar_streamers(void *&streamers);
void abrir_archivo_entrada(const char *file_name, ifstream &input);
void * leer_datos_streamer( ifstream & input);
char * leer_cadena( ifstream & input, char del);
char * asignar_cadena(char * buffer);
void cargar_comentarios(void *&comentarios);
void incrementar_espacios(void **&arr_streamers, int &n_streamers, int &capacidad);
void * leer_datos_comentario( ifstream & input);
void aumentar_espacios(void **&arr_coment, int &n_comentarios, int &capacidad);
void actualizar_comentarios(void * streamers, void * comentarios);
void agregar_espacios(void *&comentarios, int &n_comentarios, int &capacidad);
void imprimir_streamers(void * streamers);
void abrir_archivo_salida(const char *file_name, ofstream &output);
void imprimir_linea(int n, char c,ofstream &output);
void imprimir_comentarios(void * dato, ofstream & output);

#endif //INC_2025_2_FUNCIONES_HPP
