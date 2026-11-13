//
// Created by User on 12/11/2026.
//

#include "AdministrarMetricas.hpp"

class Metrica * AdministrarMetricas::rservar_memoria(const string &tipo) {
    if (tipo == "BASIC") return new MetricaBasica();
    if (tipo == "ENGAGEMENT") return new MetricaEngagement();
    if (tipo == "QUALITY") return new MetricaCalidad();
    return nullptr;
}

void AdministrarMetricas::cargarArchivo(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        string tipo, id_streamer;
        getline(input, tipo, ',');
        if (input.eof()) break;
        getline(input, id_streamer, ',');
        class Metrica *metrica = rservar_memoria(tipo);
        if (metrica == nullptr) input.ignore(200, '\n');
        metrica->leer(input);
        listaDeMetricas.insertar(metrica);
    }
    input.close();
}

void AdministrarMetricas::generarReporte(const string &file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    output<<fixed;
    output.precision(2);
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+19)/2)<<"REPORTE DE METRICAS"<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);

    int activas=0, expiradas=0;
    listaDeMetricas.imprimir(activas, expiradas, output);
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<"[TOTAL] METRICAS ACTIVAS: "<<activas<<" | METRICAS EXPIRADAS: "<<expiradas<<" | FECHA DE REPORTE: "<<FECHA_ACTUAL<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);
    output.close();
}

void AdministrarMetricas::eliminarNodos() {
    listaDeMetricas.eliminarNodos();
}

void AdministrarMetricas::eliminarLista() {
    listaDeMetricas.eliminarLista();
}

void AdministrarMetricas::generarReporteArbolABB(const string &file_name) {
    ofstream output;
    Utils::abrir_archivo(output, file_name);

    output<<fixed;
    output.precision(2);
    Utils::imprimir_linea(ANCHO, '=', output);
    output<<setw((ANCHO+19)/2)<<"REPORTE DE METRICAS"<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);

    int activas=0, expiradas=0;
    arbolDeMetricas.imprimir(output, activas, expiradas);
    Utils::imprimir_linea(ANCHO, '-', output);
    output<<"[TOTAL] METRICAS ACTIVAS: "<<activas<<" | METRICAS EXPIRADAS: "<<expiradas<<" | FECHA DE REPORTE: "<<FECHA_ACTUAL<<endl;
    Utils::imprimir_linea(ANCHO, '=', output);
    output.close();
}

void AdministrarMetricas::cargarArchivoArbolABB(const string &file_name) {
    ifstream input;
    Utils::abrir_archivo(input, file_name);

    while (true) {
        string tipo, id_streamer;
        getline(input, tipo, ',');
        if (input.eof()) break;
        getline(input, id_streamer, ',');
        class Metrica *metrica = rservar_memoria(tipo);
        if (metrica == nullptr) input.ignore(200, '\n');
        metrica->leer(input);
        arbolDeMetricas.insertar(metrica);
    }
    input.close();
}

void AdministrarMetricas::eliminarNodosArbolABB() {
    arbolDeMetricas.eliminarNodosABB();
}

void AdministrarMetricas::eliminarArbolABB() {
    arbolDeMetricas.destruirArbol();
}
