//
// Created by alois on 1/9/26.
//

#include "Sobrecargas.hpp"

void abrir_archivo_entrada(const char *file_name, ifstream &input) {
    input.open(file_name, ios::in);
    if (not input.is_open()) {
        cout << "No se abrio el archivo de entrada: " << file_name << endl;
        exit(1);
    }
}

void abrir_archivo_salida(const char *file_name, ofstream &output) {
    output.open(file_name, ios::out);
    if (not output.is_open()) {
        cout << "No se abrio el archivo de salida: "<<file_name << endl;
        exit(1);
    }
}

char * asignar_cadena(char * origen) {
    char *cadena;
    cadena = new char[strlen(origen)+1];
    strcpy(cadena, origen);
    return cadena;
}

char * leer_cadena(ifstream &input, char del) {
    char buffer[100]{};
    input.getline(buffer, 100, del);
    return asignar_cadena(buffer);
}

double leer_double(ifstream &input) {
    double dato;
    input>>dato;
    input.get();
    return dato;
}

int leer_int(ifstream &input) {
    int dato;
    input>>dato;
    input.get();
    return dato;
}

char leer_char(ifstream & input) {
    char dato;
    input>>dato;
    input.get();
    return dato;
}

void inicilizar_alumno(struct Alumnos & a) {
    a.codigo = 0;
    a.nombre = nullptr;
    a.tipo = 0;
}

void operator<<(ofstream &output, const struct Cursos& c) {
    output<<left<<setw(12)<<c.codigo<<c.nombre<<endl<<right;
    output<<c.docente<<endl;
    output<<setw(32)<<"Alumnos presenciales:"<<c.numpresencial<<endl;
    output<<setw(32)<<"Alumnos semipresenciales:"<<c.numsemipresencial<<endl;
    output<<setw(32)<<"Alumnos virtuales:"<<c.numvirtual<<endl;
    output<<c.tipofinal<<endl;
}

void operator++(struct Cursos& c, int i) {
    double promedio=0;
    promedio = (c.numpresencial*1.0)/(c.numvirtual + c.numsemipresencial + c.numpresencial)*100.0;
    if (promedio>=50) c.tipofinal = asignar_cadena("La clase se dictará en aula");
    else c.tipofinal = asignar_cadena("La clase se dictará 100% virtual");

}

int operator>=(struct Cursos* arr, struct Cursos& c) {
    int i=0;
    while (arr[i].codigo != nullptr) {
        if (arr[i]>c.codigo) return i;
        i++;
    }
    return -1;
}

int operator<=(struct Alumnos* arr, struct Alumnos& a) {
    int i=0;
    while (arr[i].codigo!=0) {
        if (arr[i]>a.codigo) return i;
        i++;
    }
    return -1;
}

void operator+=( struct Cursos& c, struct Alumnos& a) {
    if (a.tipo=='P') {
        c.presencial[c.numpresencial].codigo = a.codigo;
        c.presencial[c.numpresencial].nombre = asignar_cadena(a.nombre);
        c.presencial[c.numpresencial].tipo = a.tipo;
        c.numpresencial++;
        inicilizar_alumno(c.presencial[c.numpresencial]);
    }
    if (a.tipo=='S') {
        c.semipresencial[c.numsemipresencial].codigo = a.codigo;
        c.semipresencial[c.numsemipresencial].nombre = asignar_cadena(a.nombre);
        c.semipresencial[c.numsemipresencial].tipo = a.tipo;
        c.numsemipresencial++;
        inicilizar_alumno(c.semipresencial[c.numsemipresencial]);
    }
    if (a.tipo=='V') {
        c.vvirtual[c.numvirtual].codigo = a.codigo;
        c.vvirtual[c.numvirtual].nombre = asignar_cadena(a.nombre);
        c.vvirtual[c.numvirtual].tipo = a.tipo;
        c.numvirtual++;
        inicilizar_alumno(c.vvirtual[c.numvirtual]);
    }
}

bool operator>(const struct Cursos& c, char *codigocurso) {
    return strcmp(c.codigo, codigocurso) == 0;
}

bool operator>(const struct Alumnos& a, int codigoalumno) {
    return a.codigo==codigoalumno;
}

void operator>>(ifstream &input, struct Alumnos& a) {
    int cod;
    cod = leer_int(input);
    if (input.eof()) return;
    a.codigo = cod;
    a.nombre = leer_cadena(input, ',');
    a.tipo = leer_char(input);
}

void operator>>(ifstream &input,struct Cursos &curso) {
    char buffer[8]{};
    input.getline(buffer, 8, ',');
    if (input.eof()) return;
    curso.codigo = asignar_cadena(buffer);
    curso.nombre = leer_cadena(input, ',');
    curso.creditos = leer_double(input);
    int cod_docente = leer_int(input);
    curso.docente = leer_cadena(input, '\n');
    curso.numpresencial=0;
    curso.numsemipresencial=0;
    curso.numvirtual=0;
    curso.tipofinal = nullptr;
}

