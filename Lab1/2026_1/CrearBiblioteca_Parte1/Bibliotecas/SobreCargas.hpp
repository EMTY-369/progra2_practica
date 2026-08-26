//
// Created by alois on 25/8/26.
//

#ifndef CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
#define CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
#include "Funciones.hpp"

void operator>>(const char* , struct Mascota& );
void operator>>(const char* , struct Veterinario& );
void operator>>(const char* , struct Atencion& );

#endif //CREARBIBLIOTECA_PARTE1_SOBRECARGAS_HPP
