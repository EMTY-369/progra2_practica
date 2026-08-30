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
void registrarAtenciones(const char * file_name, struct Atencion *&arr_atenciones, int &n_atenciones);
void validar_guardar(ifstream &input, const struct Atencion & atencion, struct Atencion *&arr_atenciones, int &n_atenciones, int &
                     s_programar, int id_inicia);
void copiar_struct(struct Atencion & destino, const struct Atencion & origen);
void listaMascotasAEsterilizar(const struct Mascota *mascota, int num_mascotas, int fecha_actural, const char *file_name);
void imprimir_titulo(const char*title, ofstream & output);
void imprimir_linea(int n, char c, ofstream & output, bool slash=true);
void centrear(const char *texto, int espacio, ofstream & output, bool slash = true, char c=' ');
void imprimirMascotasConAtenciones(const struct SistemaHuellitas &sistema, const char * file_name);
void buscar_imprimir_atenciones(struct SistemaHuellitas sistema, int id_mascota, ofstream & output);


#endif //USARBIBLIOTECA_PARTE2_FUNCIONES_HPP
