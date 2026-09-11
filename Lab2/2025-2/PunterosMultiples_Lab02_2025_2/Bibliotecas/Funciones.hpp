//
// Created by User on 10/09/2026.
//

#ifndef PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_HPP
#define PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_HPP
#include "Utils.hpp"

void abrir_archivo_entrada(const char *filename, ifstream &input);
void cargar_categorias(const char *file_name, char ***&categorias);
void agregarMemoriaPorIncrementoCat(char ***&categorias, int &n_cat, int &capacidad);
char * asignar_cadena(char * buffer);
char * leer_cadena(ifstream & input, char del);
void cargar_streamers(const char *file_name, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores);
void agregarMemoriaPorIncrementoStreamers(char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores,
                                          int &n_streamers, int &capacidad);
void leer_guardar_datos(ifstream & input, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores, int n_streamers, char
                        *buffer);
int leer_fecha( ifstream &input);
long long leer_long( ifstream & input);
void recortar_cat(char ***&categorias, int n_cat);
void recortar_streamers(int n_streamers, char ***&streamers, int **&fechas_promedios, long long **&tiempo_rep_seguidores);
void cargar_comentarios(const char *file_name, char ***&comentarios, char ***&etiquetas);
void agregarMemoriaPorIncrementoComentarios(char ***&comentarios, int &n_com, int &capacidad);
char ** cargar_lista_menciones(char *menciones);
void recortar_comentarios(char ***&comentarios, int n_com);
void imprimir_reporte(const char *file_name, char ***&categorias, char ***&streamers, int **&fechas_promedios,
                      long long **&tiempo_rep_seguidores, char ***&comentarios, char ***&etiquetas);
void abrir_archivo_salida(const char *file_name, ofstream &output);
void imprimir_streamer(char **&streamer, int *&fechas_promedio, long long *&tiempo_rep_seguidore, char ***&comentarios,
                      char ***&etiquetas, ofstream &output);
void imprimir_linea(int n, char c, ofstream & output);


#endif //PUNTEROSMULTIPLES_LAB02_2025_2_FUNCIONES_HPP
