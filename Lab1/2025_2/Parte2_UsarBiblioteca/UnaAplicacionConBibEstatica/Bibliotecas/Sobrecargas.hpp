//
// Created by alois on 1/9/26.
//

#ifndef FUENTES_BIBLIOTECA_2025_2_SOBRECARGAS_HPP
#define FUENTES_BIBLIOTECA_2025_2_SOBRECARGAS_HPP
#include "Utils.hpp"
#include "../Estructuras/Estructuras.h"

void operator>>(ifstream &, struct Cursos&);
void operator>>(ifstream &, struct Alumnos&);
bool operator>(const struct Alumnos&, int );
bool operator>(const struct Cursos&, char *);
void operator+=(struct Cursos&, struct Alumnos&);
int operator<=(struct Alumnos*, struct Alumnos&);
int operator>=(struct Cursos*, struct Cursos&);
void operator++(struct Cursos&, int);
void operator<<(ofstream &, const struct Cursos&);


char * asignar_cadena(char *);
char * leer_cadena(ifstream &, char );
double leer_double(ifstream &);
int leer_int(ifstream &);
void inicilizar_alumno(struct Alumnos &);

void abrir_archivo_entrada(const char *, ifstream &);
void abrir_archivo_salida(const char *, ofstream &);


#endif //FUENTES_BIBLIOTECA_2025_2_SOBRECARGAS_HPP
