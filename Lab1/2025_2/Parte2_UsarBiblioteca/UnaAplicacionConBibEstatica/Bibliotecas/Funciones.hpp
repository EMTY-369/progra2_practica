//
// Created by User on 2/09/2026.
//

#ifndef UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP
#define UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP
#include "Sobrecargas.hpp"
void cargar_alumnos(const char * file_name, struct Alumnos *& arr, int &n_alumnos);
void cargar_cursos(const char * file_name, struct Cursos *& arr, int &n_cursos);
void cargar_matriculas(const char *file_name, struct Cursos *cursos, struct Alumnos *alumnos);
void actualizar_cursos(struct Cursos * cursos);
void imprimir_reporte(const char * file_name,const struct Cursos * cursos);


#endif //UNAAPLICACIONCONBIBESTATICA_FUNCIONES_HPP
