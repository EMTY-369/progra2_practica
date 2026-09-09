//
// Created by User on 2/09/2026.
//

#ifndef BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
#define BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP

#include "Utils/Fuciones.hpp"
#include "Models/CadenaDeCaracteres.hpp"

void operator!(struct CadenaDeCaracteres &);
void operator<=(struct CadenaDeCaracteres &, char *);
void operator<=(struct CadenaDeCaracteres &, int);
void operator<=(struct CadenaDeCaracteres &,CadenaDeCaracteres &);
bool operator+=(struct CadenaDeCaracteres &, char *);
bool operator+=(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
int compare(struct CadenaDeCaracteres &, char *);
bool operator==(struct CadenaDeCaracteres &, char *);
bool operator>(struct CadenaDeCaracteres &, char *);
bool operator<(struct CadenaDeCaracteres &, char *);
int compare(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
bool operator==(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
bool operator>(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
bool operator<(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
int operator>>(ifstream &, struct CadenaDeCaracteres &);
void operator&&(struct CadenaDeCaracteres &, struct CadenaDeCaracteres &);
void operator<<(ofstream &, struct CadenaDeCaracteres &);

#endif //BIBLIOTECA_2025_1_FUENTES_SOBRECARGAS_HPP
