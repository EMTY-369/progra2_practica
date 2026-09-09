//
// Created by User on 3/09/2026.
//

#include "Sobrecargas.hpp"

void operator<<(ofstream &output, struct Repartidor &r) {
    output<<fixed;
    output.precision(2);
    output<<left<<setw(65)<<r.nombre<<setw(20)<<r.tipoDeVehiculo<<right<<setw(9)<<r.pagoPorEntregas<<endl;
    output<<"ORDENES ENTREGADAS:"<<endl;
    for (int i = 0; i < r.cantidadDeOrdenes; i++) {
        imprimir_ordenes(r.ordenesDeCompra[i], output);
    }
}

void operator<<(ofstream &output, struct Plato &p) {
    output<<fixed;
    output.precision(2);
    output<<left<<setw(10)<<p.codigo<<setw(65)<<p.nombre<<right<<setw(7)<<p.precio<<setw(6)
          <<p.totalDePedidos<<setw(14)<<p.totalRecaudado<<endl;
}

void operator!(struct Repartidor &r) {
    for (int i = 0; i < r.cantidadDeOrdenes; i++) {
        r.pagoPorEntregas += r.ordenesDeCompra[i].montoPorCobrar + r.ordenesDeCompra[i].pagoPorEnvio;
    }
}

void operator!(struct OrdenDeCompra &o) {
    for (int i=0; i<o.cantidadDePlatos; i++) {
        o.montoPorCobrar +=o.platosSolicitados[i].precio * o.platosSolicitados[i].cantidad * 1.0;
    }
    if (o.distancia<8) o.pagoPorEnvio = 10.50;
    if (o.distancia>=8 and o.distancia<12) o.pagoPorEnvio = 14.80;
    if (o.distancia>=12 and o.distancia<20) o.pagoPorEnvio = 23.60;
    if (o.distancia>=20) o.pagoPorEnvio = 31.70;
}

void operator<=(struct Repartidor *arr_r, struct Pedido &p) {
    int pos_r = buscar_repartidor(p.codigoDelRepartidor, arr_r);
    if (pos_r == -1) return;
    buscar_agregar_cliente(arr_r[pos_r], p);
}

bool operator<=(struct Pedido &pe, struct Plato *arr_pl) {
    int pos_plato=buscar_plato(pe.codigoDelPlato, arr_pl);
    if (pos_plato==-1) return false;
    strcpy(pe.codigoDelPlato, arr_pl[pos_plato].codigo);
    arr_pl[pos_plato].totalDePedidos += pe.cantidad;
    pe.precio = arr_pl[pos_plato].precio;
    return true;
}

void operator>>(ifstream &input, struct Pedido &p) {
    //34571095  BR-272     2    RAK361    1.33
    int dni;
    input>>dni;
    if (input.eof()) return;
    p.dniDelCliente = dni;
    //input>>ws;
    input>>p.codigoDelPlato>>p.cantidad>>p.codigoDelRepartidor>>p.distanciaARecorrer;
    p.precio = 0;
}

void operator>>(ifstream &input, struct Repartidor &r) {
    //JNV387,Justino Norabuena Virginia Karina,Motocicleta
    char buffer[MAX_CADENA]{};
    input.getline(buffer, MAX_CADENA, ',');
    if (input.eof()) {
        strcpy(r.codigo, "FIN");
        return;
    }
    strcpy(r.codigo, buffer);
    input.getline(r.nombre, MAX_CADENA, ',');
    input.getline(r.tipoDeVehiculo, MAX_CADENA, '\n');
    r.cantidadDeOrdenes = 0;
    r.pagoPorEntregas = 0;
}

void operator>>(ifstream &input, struct Plato &p) {
    //AP-500,CHORIZOS COCKTAIL,12.90,APERITIVO
    char buffer[MAX_CADENA]{};
    input.getline(buffer, MAX_CADENA, ',');
    if (input.eof()) {
        strcpy(p.codigo, "FIN");
        return;
    }
    strcpy(p.codigo, buffer);
    input.getline(p.nombre, MAX_CADENA, ',');
    p.precio = leer_double(input);
    p.totalDePedidos = 0;
    p.totalRecaudado = 0;
    input.ignore(MAX_CADENA, '\n');
}
