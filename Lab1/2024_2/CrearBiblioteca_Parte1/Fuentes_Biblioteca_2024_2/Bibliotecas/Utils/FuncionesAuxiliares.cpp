//
// Created by User on 3/09/2026.
//

#include "FuncionesAuxiliares.hpp"
#include "../Models/Estructuras.h"

void abrir_archivo_salida(const char * file_name,ofstream &output) {
    output.open(file_name,ios::out);
    if (not output.is_open()) {
        cout<<"Error al abrir archivo de salida"<<endl;
        exit(1);
    }
}

void abrir_archivo_entrada(const char * file_name, ifstream & input) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "Error al abrir el archivo de entrada" << endl;
        exit(1);
    }
}

void imprimir_ordenes(const struct OrdenDeCompra &o, ofstream &output) {
    output<<setw(5)<<""<<o.dniDelCliente<<setw(7)<<o.distancia<<setw(15)<<o.montoPorCobrar<<setw(11)<<o.pagoPorEnvio<<endl;
    output<<setw(5)<<""<<"Platos solicitados:"<<endl;
    for (int i=0;i<o.cantidadDePlatos;i++) {
        output<<setw(5)<<""<<"-  "<<o.platosSolicitados[i].codigo<<setw(9)<<o.platosSolicitados[i].precio;
        output<<o.platosSolicitados[i].cantidad<<setw(12)<<o.platosSolicitados[i].cantidad*o.platosSolicitados[i].precio<<endl;
    }
}

void inicializar_orden(struct OrdenDeCompra &o, int dni) {
    o.dniDelCliente = dni;
    o.cantidadDePlatos = 0;
    o.distancia = 0;
    o.montoPorCobrar = 0;
    o.pagoPorEnvio = 0;
}

void inicializar_plato_solicitado(struct PlatoSolicitado &pl,const struct Pedido &pe) {
    strcpy(pl.codigo, pe.codigoDelPlato);
    pl.precio = pe.precio;
    pl.cantidad = 0;
}

void buscar_agregar_plato(struct Repartidor &r, const struct Pedido &p, int pos) {
    int i=0;
    bool encontrado = false;
    for (i=0;i<r.ordenesDeCompra[pos].cantidadDePlatos;i++) {
        if (strcmp(r.ordenesDeCompra[pos].platosSolicitados[i].codigo, p.codigoDelPlato)==0) {
            encontrado = true;
            break;
        }
    }
    if (not encontrado) {
        inicializar_plato_solicitado(r.ordenesDeCompra[pos].platosSolicitados[i], p);
        r.cantidadDeOrdenes ++;
    }
    r.ordenesDeCompra[pos].platosSolicitados[i].cantidad += p.cantidad;
}

void buscar_agregar_cliente(struct Repartidor & r, const struct Pedido & p) {
    int i=0;
    bool encontrado = false;
    for (i=0;i<r.cantidadDeOrdenes;i++) {
        if (r.ordenesDeCompra[i].dniDelCliente==p.dniDelCliente) {
            encontrado = true;
            break;
        }
    }
    if (not encontrado) inicializar_orden(r.ordenesDeCompra[i], p.dniDelCliente);
    r.ordenesDeCompra[i].cantidadDePlatos += p.cantidad;
    r.ordenesDeCompra[i].distancia += p.distanciaARecorrer;
    //r.ordenesDeCompra[i].montoPorCobrar += p.precio * p.cantidad;
    buscar_agregar_plato(r, p, i);
}

int buscar_repartidor(char * cod, struct Repartidor * arr) {
    int i=0;
    while (strcmp("FIN", arr[i].codigo)!=0) {
        if (strcmp(cod, arr[i].codigo)==0) return i;
        i++;
    }
    return -1;
}

int buscar_plato(char *cod, struct Plato * pl) {
    int i=0;
    while (strcmp("FIN", pl[i].codigo)!=0) {
        if (strcmp(cod, pl[i].codigo)==0) return i;
        i++;
    }
    return -1;
}

double leer_double(ifstream & input) {
    double dato;
    input>>dato;
    input.ignore();
    return dato;
}
