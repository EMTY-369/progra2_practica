//
// Created by alois on 25/8/26.
//

#include "SobreCargas.hpp"

//Sobrecargas

void operator>>(ifstream& input, struct Mascota& m) {
    //101,Luna,Labrador,Negro,CANINO,10/10/2024
    int id;
    input>>id;
    if (input.eof()) return;
    m.idMascota = id;
    input.ignore();
    m.nombre = leer_cadena(input, ',');
    m.raza = leer_cadena(input, ',');
    m.color = leer_cadena(input, ',');
    m.tipo = leer_cadena(input, ',');
    m.fechaNacimiento = leer_fecha(input);

}

void operator>>(ifstream& input, struct Veterinario& v) {
    //201,Miguel Perez,MedicinaGeneral
    int id;
    input>>id;
    if (input.eof()) return;
    v.idVeterinario = id;
    input.ignore();
    v.nombre = leer_cadena(input, ',');
    v.especialidad = leer_cadena(input, '\r');

}

void operator>>(ifstream& input, struct Atencion& a) {
    //101,204,7/4/2025,CONTROL,11:00,PROGRAMADA
    int id;
    input>>id;
    if (input.eof()) return;
    a.idMascota = id;
    char c;
    input>>c>>a.idVeterinario>>c;
    a.fecha = leer_fecha(input);
    input.ignore();
    a.tipoAtencion = leer_cadena(input, ',');
    input>>a.hora>>c>>a.minutos>>c;
    a.estado = leer_cadena(input, '\r');

}

bool operator==(const struct Atencion& A, const struct Atencion& B) {
    return A.idMascota == B.idMascota and A.idVeterinario == B.idVeterinario and A.fecha == B.fecha and
        A.hora == B.hora and A.minutos == B.minutos and strcmp(A.tipoAtencion, B.tipoAtencion)==0 and
        strcmp(A.estado, B.estado)==0;
}

bool operator<=(const struct Mascota& m, int fecha) {
    return m.fechaNacimiento <= fecha;
}

void operator<<(ofstream& output, const struct Mascota& m) {

    output<<"ID:  "<<m.idMascota<<endl;
    output<<"     Nombre:  "<<m.nombre<<endl;
    output<<"     Raza:  "<<m.raza<<endl;
    output<<"     Color:  "<<m.color<<endl;
    output<<"     Tipo:  "<<m.tipo<<endl;

}

void operator<<(ofstream& output,const struct Atencion& a) {

    output<<"Fecha:"<<setw(14)<<a.fecha;
    output<<",  ID:"<<setw(8)<<a.idAtencion;
    output<<",  Veterinario:  "<<setw(6)<<a.idVeterinario;
    output<<",  Tipo:  "<<a.tipoAtencion;
    output<<",  Estado:  "<<a.estado<<endl;

}


//Funciones
void abrir_archivo_entrada(const char * file_name, ifstream & input) {
    input.open(file_name, ios::in);
    if(not input.is_open()) {
        cout << file_name << " no encontrado" << endl;
        exit(1);
    }
}

void abrir_archivo_salida(const char * file_name, ofstream & output) {
    output.open(file_name, ios::out);
    if(not output.is_open()) {
        cout << file_name << " no encontrado" << endl;
        exit(1);
    }
}


char * asignar_cadena(char * buffer) {
    char *cadena;
    cadena = new char[strlen(buffer)+1];
    strcpy(cadena, buffer);
    return cadena;
}

char * leer_cadena( ifstream & input, char del) {
    char buffer[50]{};
    input.getline(buffer, 50, del);
    return asignar_cadena(buffer);
}

int leer_fecha( ifstream & input) {
    int aa, dd, mm;
    char c;
    input>>dd>>c>>mm>>c>>aa;
    return aa*10000 + mm*100 + dd;
}