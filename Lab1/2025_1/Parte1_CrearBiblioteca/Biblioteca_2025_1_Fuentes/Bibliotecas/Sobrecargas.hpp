//
// Created by User on 2/09/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#define BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#include "Utils.hpp"
#include "../Estructuras/CadenaDeCaracteres.hpp"

void operator!(struct CadenaDeCaracteres &);
void operator<=(struct CadenaDeCaracteres &, char *);
void operator<=(struct CadenaDeCaracteres &, int);
void operator<=(struct CadenaDeCaracteres &,CadenaDeCaracteres &);
bool operator+=(struct CadenaDeCaracteres &, char *);
bool operator+=(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
int compare(struct CadenaDeCaracteres &, char *);
bool operator==(struct CadenaDeCaracteres &, char *);

char * asignar_cadena(char *);

#endif //BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
