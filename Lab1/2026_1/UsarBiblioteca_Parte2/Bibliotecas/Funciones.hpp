//
// Created by alois on 28/8/26.
//

#ifndef USARBIBLIOTECA_PARTE2_FUNCIONES_HPP
#define USARBIBLIOTECA_PARTE2_FUNCIONES_HPP
#include "SobreCargas.hpp"

void cargarDatos(const char * file_mascota, const char * file_veterinario, struct Mascota *&arr_mascotas, struct Veterinario *&arr_veterinarios,
                 int &n_mascotas, int &n_veterinarios);
void cargar_mascotas(ifstream &input, struct Mascota *&mascotas, int &n_mascotas);
void cargar_veterinarios(ifstream & input, struct Veterinario *&veterinarios, int &n_veterinarios);


#endif //USARBIBLIOTECA_PARTE2_FUNCIONES_HPP
