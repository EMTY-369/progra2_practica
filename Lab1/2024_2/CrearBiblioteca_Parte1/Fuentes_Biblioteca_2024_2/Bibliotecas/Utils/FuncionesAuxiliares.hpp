//
// Created by User on 3/09/2026.
//

#ifndef FUENTES_BIBLIOTECA_2024_2_FUNCIONESAUXILIARES_HPP
#define FUENTES_BIBLIOTECA_2024_2_FUNCIONESAUXILIARES_HPP
#include "Utils.hpp"
#include "../Models/Estructuras.h"
double leer_double(ifstream & input);
int buscar_plato(char *cod, struct Plato * pl);
int buscar_repartidor(char * cod, struct Repartidor * arr);
void buscar_agregar_cliente(struct Repartidor & repartidor, const struct Pedido & pedido);
void inicializar_orden(struct OrdenDeCompra &o, int dni);
void buscar_agregar_plato(struct Repartidor & r, const struct Pedido &p, int pos);
void inicializar_plato_solicitado(struct PlatoSolicitado &pl,const struct Pedido &pe);
void imprimir_ordenes(const struct OrdenDeCompra &o, ofstream &output);
void abrir_archivo_entrada(const char * file_name, ifstream & input);
void abrir_archivo_salida(const char * file_name,ofstream &output);

#endif //FUENTES_BIBLIOTECA_2024_2_FUNCIONESAUXILIARES_HPP
