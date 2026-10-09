//
// Created by User on 8/10/2026.
//

#include "Streamer.hpp"

void Streamer::get_cuenta(char *ptr_cad) const {
    if (this->cuenta == nullptr) ptr_cad[0] = '\0';
    else strcpy(ptr_cad, this->cuenta);
}

void Streamer::set_cuenta(char * const cuenta) {
    if (this->cuenta != nullptr) delete[] this->cuenta;
    this->cuenta = Utils::asignar_cadena(cuenta);
}

long long Streamer::get_tiempo_total() const {
    return tiempo_total;
}

void Streamer::set_tiempo_total(const long long tiempo_total) {
    this->tiempo_total = tiempo_total;
}

double Streamer::get_promedio_spectadores() const {
    return promedio_spectadores;
}

void Streamer::set_promedio_spectadores(const double promedio_spectadores) {
    this->promedio_spectadores = promedio_spectadores;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(const int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

void Streamer::get_categoria(char *ptr_cad) const {
    if (this->categoria == nullptr) ptr_cad[0] = '\0';
    else strcpy(ptr_cad, categoria);
}

void Streamer::set_categoria(char * const categoria) {
    if (this->categoria != nullptr) delete[] this->categoria;
    this->categoria = Utils::asignar_cadena(categoria);
}

Streamer::Streamer() {
    cuenta = nullptr;
    tiempo_total = 0;
    promedio_spectadores = 0;
    n_seguidores = 0;
    categoria = nullptr;
}

Streamer::Streamer(char * const cuenta, const long long tiempo_total, const double promedio_spectadores,
    const int n_seguidores, char * const categoria) {
    this->cuenta = nullptr;
    this->categoria = nullptr;
    this->tiempo_total = tiempo_total;
    this->promedio_spectadores = promedio_spectadores;
    this->n_seguidores = n_seguidores;
    set_cuenta(cuenta);
    set_categoria(categoria);
}

Streamer::~Streamer() {
    delete[] this->cuenta;
    delete[] this->categoria;
}

void Streamer::leer_streamer(ifstream &input) {
    char buffer[MAX_CAD]{};
    input.getline(buffer, MAX_CAD, ',');
    if (input.eof()) return;
    set_cuenta(buffer);
    input>>tiempo_total;
    input.get();
    input>>promedio_spectadores;
    input.get();
    input>>n_seguidores;
    input.get();
    categoria = Utils::leer_cadena(input, '\n');
}

void Streamer::mostrar_streamer_arch(ofstream &output) {
    output<<left<<setw(30)<<cuenta<<setw(20)<<tiempo_total<<setw(20)<<promedio_spectadores
          <<setw(20)<<n_seguidores<<setw(30)<<categoria<<right<<endl;
}

void Streamer::mostrar_streamer_consola() {
    cout<<left<<setw(30)<<cuenta<<setw(20)<<tiempo_total<<setw(20)<<promedio_spectadores
          <<setw(20)<<n_seguidores<<setw(30)<<categoria<<right;
}

void Streamer::copiar(const class Streamer &s) {
    this->cuenta = Utils::asignar_cadena(s.cuenta);
    this->tiempo_total = s.tiempo_total;
    this->promedio_spectadores = s.promedio_spectadores;
    this->n_seguidores = s.n_seguidores;
    this->categoria = Utils::asignar_cadena(s.categoria);
}
