//
// Created by User on 11/11/2026.
//

#include "GestorAtenciones.hpp"

int GestorAtenciones::get_cantidad_atenciones() const {
    return cantidad_atenciones;
}

void GestorAtenciones::set_cantidad_atenciones(const int cantidad_atenciones) {
    this->cantidad_atenciones = cantidad_atenciones;
}

int GestorAtenciones::get_capacidad() const {
    return capacidad;
}

void GestorAtenciones::set_capacidad(const int capacidad) {
    this->capacidad = capacidad;
}

void GestorAtenciones::eliminar_profundo() {
    for (int i = 0; i < cantidad_atenciones; i++) delete atenciones[i];
    delete[] atenciones;
}

void GestorAtenciones::reservar_memoria() {
    capacidad += INC;
    if (atenciones==nullptr) atenciones = new Atencion*[capacidad];
    else {
        auto **aux = new class Atencion*[capacidad]{};
        for (int i = 0; i < cantidad_atenciones; i++) aux[i] = atenciones[i];
        delete [] atenciones;
        atenciones = aux;
    }
}

Atencion * GestorAtenciones::reservar_memoria_atencion(char tipo) {
    if (tipo == '1') return new Emergencia;
    if (tipo == '2') return new Urgencia;
    if (tipo == '3') return new NoUrgencia;
    return nullptr;
}

void GestorAtenciones::agregar_atencion(class Atencion *atencion) {
    if (cantidad_atenciones == capacidad) reservar_memoria();
    atenciones[cantidad_atenciones++] = atencion;
}

void GestorAtenciones::cargar_atenciones(const string &file_name, int hora) {
    string name = file_name + "/";
    if (hora < 10) name = name + "0";
    name = name + to_string(hora) + ".csv";

    ifstream input;
    Utils::abrir_archivo(name, input);
    char tipo;
    while (true) {
        input>>tipo;
        if (input.eof()) break;
        input.get();
        class Atencion *a = reservar_memoria_atencion(tipo);
        if (a == nullptr) {input.ignore(200,'\n'); continue;}
        a->leer(input, hora);
        agregar_atencion(a);
    }
    input.close();
}

void GestorAtenciones::procesar_dia(const string &fecha) {
    string copy, file_name;
    copy = fecha;
    copy[7] = copy[4] = '/';
    file_name = "ArchivosDeDatos/" + copy;

    for (int i = 0; i < 24; i++) {
        //cargar_atenciones(file_name, i);
        cargar_atenciones_prioridad(file_name,i);
        imprimir_atenciones_prioridad("ArchivosDeReporte/"+fecha+"hora"+to_string(i), fecha, i);
    }
}

void GestorAtenciones::cargar_atenciones_prioridad(const string &file_name, int hora) {
    string name = file_name + "/";
    if (hora < 10) name = name + "0";
    name = name + to_string(hora) + ".csv";

    ifstream input;
    Utils::abrir_archivo(name, input);
    char tipo;
    while (true) {
        input>>tipo;
        if (input.eof()) break;
        input.get();
        class Atencion *a = reservar_memoria_atencion(tipo);
        if (a == nullptr) {input.ignore(200,'\n'); continue;}
        a->leer(input, hora);
        listaAtenciones.insertar(a->obtener_llave(),a);
    }
    input.close();
}

void GestorAtenciones::imprimir_atenciones_prioridad(const string &base, const string &fecha, int hora) {
    ofstream output;
    Utils::abrir_archivo(base, output);
    listaAtenciones.imprimir(output, fecha, hora);
}

GestorAtenciones::GestorAtenciones() {
    atenciones = nullptr;
    cantidad_atenciones = 0;
    capacidad = 0;
}

GestorAtenciones::GestorAtenciones(const class GestorAtenciones &other) {
    capacidad = other.capacidad;
    cantidad_atenciones = other.cantidad_atenciones;

    if (cantidad_atenciones > 0) {
        atenciones = new Atencion*[capacidad];
        for (int i = 0; i < cantidad_atenciones; i++) {
            atenciones[i] = other.atenciones[i]->clonar();
        }
    } else atenciones = nullptr;
}

GestorAtenciones::~GestorAtenciones() {
    eliminar_profundo();
}
