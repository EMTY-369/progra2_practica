//
// Created by alois on 8/9/26.
//

#ifndef METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONES_HPP
#define METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONES_HPP
#include "Utils.hpp"

void abrir_archivo_entrada(const char *file_name, ifstream &input);
void cargar_informacion(const char *file_name, int *&fechas, int ***&datos_enteros, char ****&datos_de_texto,
                        double ***&datos_de_punto_flotante);
int leer_fecha_hora(ifstream & input, int i);
int leer_int(ifstream &input);
void incrementar_espacios(int *&fechas, int ***&datos_enteros, double ***&datos_de_punto_flotante, char ****&datos_de_texto,
                          int &n_datos, int &capacidad, int *&capacidades, int *&m_datos);
void insertar_ordenado(int fecha_leida, int *&fechas, int ***&datos_enteros, char ****&datos_de_texto, double ***&datos_de_punto_flotante,
                       int n_datos ,ifstream & input);
void leer_datos(char *&id, char *&nombre, int &hora_ingreso, double &temperatura, int &sistolica, int &diastolica,
                int &hora_salida, char *&especialidad, ifstream & input);
char * leer_cadena( ifstream &input, char del);
char * asignar_cadena(char * buffer);
double leer_double( ifstream & input);



#endif //METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONES_HPP
