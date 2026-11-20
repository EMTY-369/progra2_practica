//
// Created by User on 19/11/2026.
//

#include "Hora.hpp"

int Hora::get_hh() const {
    return hh;
}

void Hora::set_hh(const int hh) {
    this->hh = hh;
}

int Hora::get_mm() const {
    return mm;
}

void Hora::set_mm(const int mm) {
    this->mm = mm;
}

int Hora::get_ss() const {
    return ss;
}

void Hora::set_ss(const int ss) {
    this->ss = ss;
}

int Hora::get_segundos() const {
    return segundos;
}

void Hora::set_segundos(const int segundos) {
    this->segundos = segundos;
}

void Hora::leer(ifstream &input) {
    input >> hh;
    input.get();
    input >> mm;
    input.get();
    input >> ss;
    input.get();
    segundos = hh*3600 + mm*60 + ss;
}

void Hora::imprimir(ofstream &output) const {
    output<<setfill('0')<<setw(2)<<hh<<":"<<setw(2)<<mm<<":"<<setw(2)<<ss<<setfill(' ');
}

Hora::Hora() {
    hh = 0;
    mm = 0;
    ss = 0;
    segundos = 0;
}

void operator>>(ifstream &input, class Hora &hora) {
    hora.leer(input);
}

void operator<<(ofstream &output, const class Hora &hora) {
    hora.imprimir(output);
}
