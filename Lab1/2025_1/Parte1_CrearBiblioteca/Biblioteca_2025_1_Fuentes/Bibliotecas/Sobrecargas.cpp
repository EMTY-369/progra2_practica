//
// Created by User on 2/09/2026.
//

#include "Sobrecargas.hpp"

int compare(struct CadenaDeCaracteres &c1, char *c2) {
    for (int i=0;c1.cadena[i];i++) {
        if (not(c1.cadena[i]==c2[i] or c1.cadena[i]==c2[i]+('a'-'A') or c1.cadena[i]==c2[i]-('a'-'A'))) {
            return c1.cadena[i]-c2[i];
        }
    }
    return 0;
}

bool operator+=(struct CadenaDeCaracteres &c1, struct CadenaDeCaracteres &c2) {
    if (c1.cadena!=nullptr) {
        char buffer[MAX_CADENA]{};
        strcpy(buffer, c1.cadena);
        strcat(buffer, c2.cadena);
        delete [] c1.cadena;
        c1.cadena = asignar_cadena(buffer);
        return true;
    }
    return false;
}

bool operator+=(struct CadenaDeCaracteres &c, char *texto) {
    if (c.cadena!=nullptr) {
        char buffer[MAX_CADENA]{};
        strcpy(buffer, c.cadena);
        strcat(buffer, texto);
        delete [] c.cadena;
        c.cadena = asignar_cadena(buffer);
        return true;
    }
    return false;
}

void operator<=(struct CadenaDeCaracteres &c1,CadenaDeCaracteres &c2) {
    c1.cadena =  asignar_cadena(c2.cadena);
    c1.capacidad = c2.capacidad;
    c1.longitud = c2.longitud;
}

void operator<=(struct CadenaDeCaracteres &cadena, int n) {
    !cadena;
    cadena.cadena = new char[n+1]{};
}

char * asignar_cadena(char * origen) {
    char *cadena;
    cadena=new char[strlen(origen)+1];
    strcpy(cadena,origen);
    return cadena;
}

void operator<=(struct CadenaDeCaracteres &c, char *texto) {
    c.cadena = asignar_cadena(texto);
}

void operator!(struct CadenaDeCaracteres &cadena) {
    cadena.cadena=nullptr;
    cadena.capacidad=0;
    cadena.longitud=0;
}
