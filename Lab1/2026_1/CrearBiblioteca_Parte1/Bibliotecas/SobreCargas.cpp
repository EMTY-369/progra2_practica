//
// Created by alois on 25/8/26.
//

#include "SobreCargas.hpp"


int leer_fecha( ifstream & input);

void operator>>(const char* file_name, struct Mascota& m) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    //101,Luna,Labrador,Negro,CANINO,10/10/2024
    input>>m.idMascota;
    if (input.eof()) return;
    m.nombre = leer_cadena(input, ',');
    m.raza = leer_cadena(input, ',');
    m.color = leer_cadena(input, ',');
    m.tipo = leer_cadena(input, ',');
    m.fechaNacimiento = leer_fecha(input);
    input.close();
}

void operator>>(const char* file_name, struct Veterinario& v) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    //201,Miguel Perez,MedicinaGeneral
    input>>v.idVeterinario;
    if (input.eof()) return;
    v.nombre = leer_cadena(input, ',');
    v.especialidad = leer_cadena(input, ',');
    input.close();
}

void operator>>(const char* file_name, struct Atencion& a) {
    ifstream input;
    abrir_archivo_entrada(file_name, input);
    //101,204,7/4/2025,CONTROL,11:00,PROGRAMADA
    input>>a.idMascota;
    if (input.eof()) return;
    input>>a.idVeterinario;
    a.fecha = leer_fecha(input);
    input.get();
    a.tipoAtencion = leer_cadena(input, ',');
    char c;
    input>>a.hora>>c>>a.minutos>>c;
    a.estado = leer_cadena(input, '\n');
    input.close();
}
