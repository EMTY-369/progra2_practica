//
// Created by User on 5/11/2026.
//

#include "Streamer.hpp"

int Streamer::get_id() const {
    return id;
}

void Streamer::set_id(const int id) {
    this->id = id;
}

string Streamer::get_cuenta() const {
    return cuenta;
}

void Streamer::set_cuenta(const string &cuenta) {
    this->cuenta = cuenta;
}

int Streamer::get_n_seguidores() const {
    return n_seguidores;
}

void Streamer::set_n_seguidores(const int n_seguidores) {
    this->n_seguidores = n_seguidores;
}

string Streamer::get_categoria() const {
    return categoria;
}

void Streamer::set_categoria(const string &categoria) {
    this->categoria = categoria;
}

void Streamer::leer(ifstream &input) {
    //174920,xQcOW,PUBG,3246298,2025-10-17
    input>>id;
    input.get();
    getline(input,cuenta,',');
    getline(input,categoria,',');
    input>>n_seguidores;
    input.get();
}

void Streamer::imprimir(ofstream &output) {
    output<<"[ST] CUENTA: "<<left<<setw(25)<<cuenta<<"| SEGUIDORES: "<<right<<setw(12)<<n_seguidores;
    output<<" | CATEGORÍA: "<<left<<setw(25)<<categoria<<right<<" | TIPO: StreamerGratuito"<<endl;
    Utils::imprimir_linea(ANCHO, '-', output);
}

Streamer::Streamer() {
    id = 0;
    n_seguidores = 0;
}
