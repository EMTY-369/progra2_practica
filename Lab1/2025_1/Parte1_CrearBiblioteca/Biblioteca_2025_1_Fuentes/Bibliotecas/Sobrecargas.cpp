//
// Created by User on 2/09/2026.
//

#include "Sobrecargas.hpp"

void operator<<(ofstream &output, struct CadenaDeCaracteres &c) {
    output<<c.cadena;
}

void operator&&(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    char *aux;
    aux = asignar_cadena(c1.cadena);
    c1.cadena = c2.cadena;
    c2.cadena = aux;
}

int operator>>(ifstream & input, struct CadenaDeCaracteres & cadena) {
    char buffer[MAX_CADENA]{};
    input>>buffer;
    if (input.eof()) return 1;
    cadena.cadena = asignar_cadena(buffer);
    if ((cadena.cadena[0]>='a' and cadena.cadena[0]<='z') or (cadena.cadena[0]>='A' and cadena.cadena[0]<='Z')) return 0;
    else return -1;
}

bool operator>(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    return compare(c1,c2)>0;
}

bool operator<(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    return compare(c1,c2)<0;
}

bool operator==(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    return compare(c1, c2) == 0;
}

int compare(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    return compare(c1, c2.cadena);
}

bool operator>(struct CadenaDeCaracteres &c1, char *c2) {
    return compare(c1,c2)>0;
}

bool operator<(struct CadenaDeCaracteres &c1, char *c2) {
    return compare(c1,c2)<0;
}

bool operator==(struct CadenaDeCaracteres &c1, char *c2) {
    return compare(c1, c2) == 0;
}

int compare(struct CadenaDeCaracteres &c1, char *c2) {
    for (int i=0;c1.cadena[i];i++) {
        if (not(c1.cadena[i]==c2[i] or c1.cadena[i]==c2[i]+('a'-'A') or c1.cadena[i]==c2[i]-('a'-'A'))) {
            return c1.cadena[i]-c2[i];
        }
    }
    if (strlen(c1.cadena)==strlen(c2)) return 0;
    else return -1;
}

bool operator+=(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    return c1+=c2.cadena;
    // if (c1.cadena!=nullptr) {
    //     char buffer[MAX_CADENA]{};
    //     strcpy(buffer, c1.cadena);
    //     strcat(buffer, c2.cadena);
    //     delete [] c1.cadena;
    //     c1.cadena = asignar_cadena(buffer);
    //     return true;
    // }
    // return false;
}

bool operator+=(struct CadenaDeCaracteres &c, char *texto) {
    if (c.cadena!=nullptr) {
        char buffer[MAX_CADENA]{};
        strcpy(buffer, c.cadena);
        strcat(buffer, texto);
        delete [] c.cadena;
        c <= buffer;
        return true;
    }
    return false;
}

void operator<=(struct CadenaDeCaracteres &c1,CadenaDeCaracteres &c2) {
    c1 <= asignar_cadena(c2.cadena);
    c1.capacidad = c2.capacidad;
    c1.longitud = c2.longitud;
}

void operator<=(struct CadenaDeCaracteres &cadena, int n) {
    !cadena;
    cadena.cadena = new char[n+1]{};
}

void operator<=(struct CadenaDeCaracteres &c, char *texto) {
    c.cadena = asignar_cadena(texto);
}

void operator!(struct CadenaDeCaracteres &cadena) {
    cadena.cadena=nullptr;
    cadena.capacidad=0;
    cadena.longitud=0;
}
