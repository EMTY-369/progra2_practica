//
// Created by alois on 25/8/26.
//

#ifndef CREARBIBLIOTECA_PARTE1_SISTEMAHUELLITAS_HPP
#define CREARBIBLIOTECA_PARTE1_SISTEMAHUELLITAS_HPP
#include "Mascota.hpp"
#include "Veterinario.hpp"
#include "Atencion.hpp"
struct SistemaHuellitas {
    struct Mascota* mascotas;
    struct Veterinario* veterinarios;
    struct Atencion* atenciones;
    int numMascotas;
    int numVeterinarios;
    int numAtenciones;
};
#endif //CREARBIBLIOTECA_PARTE1_SISTEMAHUELLITAS_HPP
