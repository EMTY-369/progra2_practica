//
// Created by User on 30/09/2026.
//

#include "BibliotecaRegistros.hpp"


void imprimir_encabezado(ofstream & output) {
    output<<left<<setw(14)<<"FECHA"<<setw(8)<<"HORA"<<setw(10)<<"CODIGO"<<setw(30)<<"NOMBRE"
          <<setw(20)<<"RAZA"<<setw(20)<<"COLOR"<<endl<<right;
    imprimir_linea(ANCHO,'=',output);
}

void imprime_registro(ofstream &output, const void *registro) {
    void **arr = (void **)registro;
    static int i=0;
    if (i==0) imprimir_encabezado(output);
    imprimir_fecha(*(int *)arr[FECHA], output);
    output<<setw(4)<<"";
    imprimir_hora(*(int *)arr[HORA], output);
    output<<setw(3)<<""<<left<<setw(10)<<*(int *)arr[COD]<<setw(30)<<(char *)arr[NOMBRE];
    output<<setw(20)<<(char *)arr[RAZA]<<setw(20)<<(char *)arr[COLOR]<<endl<<right;
    i++;
}

bool verifica_reg(const void*a, const void*b) {
    void **arr1 = (void**)a, **arr2 = (void**)b;
    int *f1 = (int* )arr1[FECHA], *f2 = (int* )arr2[FECHA], *h1 = (int* )arr1[HORA], *h2 = (int* )arr2[HORA];
    if (*f1 != *f2) return *f1 > *f2;
    else return *h1 > *h2;

}

int compara_reg(const void *a,const void *b) {
    void **arr1 = *(void ***) a, **arr2 = *(void ***) b;
    int *f1 = (int* )arr1[FECHA], *f2 = (int* )arr2[FECHA], *h1 = (int* )arr1[HORA], *h2 = (int* )arr2[HORA];
    if (*f1 != *f2) return *f1 - *f2;
    else return *h1 - *h2;
}

void* lee_registro(ifstream &input) {
    int cod;
    input >> cod;
    if (input.eof()) return nullptr;
    input.get();
    auto *ptr_cod=new int, *ptr_f=new int, *ptr_h=new int;
    char *tipo_cita, *estado_cita, *nombre, *raza, *familia, *color;

    *ptr_cod = cod; *ptr_f = leer_fecha(input);
    tipo_cita = leer_cadena(input, ',');
    *ptr_h = leer_hora(input);
    estado_cita = leer_cadena(input, ','); nombre = leer_cadena(input, ',');
    raza = leer_cadena(input, ','); color = leer_cadena(input, ',');
    familia = leer_cadena(input, '\n');

    void **arr = new void*[9]{};
    arr[COD] = ptr_cod;        arr[FECHA] = ptr_f;
    arr[TIPO] = tipo_cita;     arr[HORA] = ptr_h;
    arr[ESTADO] = estado_cita; arr[NOMBRE] = nombre;
    arr[RAZA] = raza;          arr[COLOR] = color;
    arr[FAMILIA] = familia;
    return arr;
}
