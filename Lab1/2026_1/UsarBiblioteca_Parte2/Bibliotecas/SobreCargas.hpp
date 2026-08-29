//
// Created by alois on 25/8/26.
//

#ifndef CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
#define CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
#include "Utils.hpp"
#include "../Estructuras/SistemaHuellitas.hpp"

void operator>>(ifstream& , struct Mascota& );
void operator>>(ifstream& , struct Veterinario& );
void operator>>(ifstream& , struct Atencion& );
bool operator==(const struct Atencion& , const struct Atencion& );
bool operator<=(const struct Mascota& , int );
void operator<<(ofstream& ,const struct Mascota& );
void operator<<(ofstream& ,const struct Atencion& );

void abrir_archivo_entrada(const char * file_name, ifstream & input);
char * leer_cadena( ifstream & input, char del);
char * asignar_cadena(char * buffer);
int leer_fecha( ifstream & input);
void abrir_archivo_salida(const char * file_name, ofstream & output);

#endif //CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
