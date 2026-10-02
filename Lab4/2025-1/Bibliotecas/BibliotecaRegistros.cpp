//
// Created by User on 1/10/2026.
//

#include "BibliotecaRegistros.hpp"

void imprimir_encabezado(ofstream &output) {
    output<<left<<setw(14)<<"FECHA"<<setw(14)<<"LICENCIA"<<setw(60)<<"NOMBRE"<<setw(10)<<"FALTA"<<right<<endl;
    imprimir_linea(ANCHO, '=', output);
}

void imprime_registro(ofstream &output, const void *dato) {
    static int i=0;
    if (i==0) imprimir_encabezado(output);
    void **registro = (void**)dato;

    imprime_fecha(*(int *)registro[FECHA], output);
    output<<setw(4)<<""<<left<<setw(14)<<*(int *)registro[LICENCIA]<<setw(60)<<(char *)registro[NOMBRE]
          <<setw(10)<<*(int *)registro[FALTA]<<endl;
    i++;
}

void *clasifica_resgistro(void **listaTAD, const void *dato) {
    void **registro = (void **)dato;
    int num = *(int*)registro[FALTA];
    if (num/100 == 1) return listaTAD[INICIO1];
    else return listaTAD[INICIO2];
}

void *lee_registro(ifstream &input) {
    int num;
    input >> num;
    if (input.eof()) return nullptr;
    input.get();
    int *ptr_licencia = new int{num}, *ptr_falta = new int, *ptr_fecha = new int;
    char *nombre;
    input.ignore(MAX_CAD, ',');
    *ptr_fecha = leer_fecha(input);
    *ptr_falta = leer_int(input);
    nombre = leer_cadena(input, '\n');

    void **registro = new void *[4]{};
    registro[FECHA] = ptr_fecha;
    registro[LICENCIA] = ptr_licencia;
    registro[FALTA] = ptr_falta;
    registro[NOMBRE] = nombre;
    return registro;
}
