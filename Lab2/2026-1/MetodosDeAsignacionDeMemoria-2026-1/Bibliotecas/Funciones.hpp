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
                       int n_datos, int *&capacidades, int *&m_datos, ifstream & input);
void leer_datos(int *&datos_ent, double *&datos_dou, char **&datos_cad, ifstream & input);
char * leer_cadena( ifstream &input, char del);
char * asignar_cadena(char * buffer);
double leer_double( ifstream & input);
void agregar_datos(int **&datos_entero, double **&datos_doubles, char ***&datos_cadenas,
                   int *&buffer_ent, double *&buffer_double, char **&buffer_cad, int &capacidades, int &m_datos);
void incrementar_espacios_2(int **&datos_entero, double **&datos_doubles, char ***&datos_cadenas, int &capacidades, int &m_datos);
int buscar_fecha(int * arr, int n, int fecha);
void completar_informacion(int *&fechas, char ****&datos_de_texto, int ***&datos_enteros, double ***&datos_de_punto_flotante);
void reporteDeAtenciones(const char *file_name,int *&fechas, char ****&datos_de_texto, int ***&datos_enteros,
                         double ***&datos_de_punto_flotante);
void abrir_archivo_salida(const char * file_name, ofstream & output);
void imprimir_titulo( ofstream & output);
void centrear(int ancho, const char *texto, ofstream & output);
void imprimir_linea(int n, char c, ofstream & output);
void imprimir_fecha_hora(int dato, ofstream & output, int tipo);
void imprimir_encabezados( ofstream &output);


#endif //METODOSDEASIGNACIONDEMEMORIA_2026_1_FUNCIONES_HPP
