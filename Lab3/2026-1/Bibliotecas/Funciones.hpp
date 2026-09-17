//
// Created by User on 16/09/2026.
//

#ifndef INC_2026_1_FUNCIONES_HPP
#define INC_2026_1_FUNCIONES_HPP
#include "Utils.hpp"

void cargar_pacientes(const char *file_name, void *&pacientes);
void abrir_archivo_lectura(const char *file_name, ifstream &input);
void * leer_datos_paciente( ifstream & input);
int leer_int( ifstream & input);
char * leer_cadena(ifstream & input, char del);
char * asignar_cadena(char * buffer);
char leer_char( ifstream & input);
void incrementar_tamanio(void **&arreglo_parcientes, int &n_pacientes, int &capacidad);
void cargar_visitas(const char *file_name, void *pacientes);
void leer_visita(void *&visita, int &cod_pac, ifstream & input);
double leer_double(ifstream & input);
int buscar_paciente(int cod_pac, void **pacientes);
void agregar_visita(void *paciente, int &n_visitas, int &capacidad, void * visita);
void incrementar_capacidad(void *&visitas, int &n_visitas, int &capacidad);
void generar_reporte(const char *file_name, void *pacientes);
void abrir_archivo_escritura(const char * ile_name, ofstream &output);
void imprimir_titulo( ofstream & output);
void imprimir_linea(int n, char c, ofstream & output);
void imprimir_paciente(void *paciente, ofstream & output);


#endif //INC_2026_1_FUNCIONES_HPP
