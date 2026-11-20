//
// Created by User on 19/11/2026.
//

#include "Package.hpp"

int Package::get_n_products() const {
    return n_products;
}

void Package::set_n_products(const int n_products) {
    this->n_products = n_products;
}

string Package::get_code() const {
    return code;
}

void Package::set_code(const string &code) {
    this->code = code;
}

double Package::get_distance() const {
    return distance;
}

void Package::set_distance(const double distance) {
    this->distance = distance;
}

double Package::get_total_weight() const {
    return total_weight;
}

void Package::set_total_weight(const double total_weight) {
    this->total_weight = total_weight;
}

double Package::get_total_value() const {
    return total_value;
}

void Package::set_total_value(const double total_value) {
    this->total_value = total_value;
}

void Package::leer(ifstream &input) {
    getline(input, code, ',');
    input >> distance;
    input.get();
    input >> n_products;
    input.get();
}

void Package::leer_productos(ifstream &input) {
    for (int i = 0; i < n_products; i++) {
        input.ignore(100,',');
        auto *p = new Product();
        p->leer(input);
        total_weight += p->get_weight();
        total_value += p->get_value();
        products.push_back(p);
    }
}

void Package::imprimir(ofstream &output) {
    output<<"Products:"<<endl;
    output<<left<<setw(20)<<"Code"<<setw(20)<<"Name"<<right<<setw(10)<<"Weight"<<setw(20)<<"Value"<<endl;
    for (int i = 0; i < n_products; i++) {
        class Product *p = products.back();
        p->imprimir(output);

        delete p;
        products.pop_back();
    }
}

Package::Package() {
    distance = 0;
    total_weight = 0;
    total_value = 0;
    n_products = 0;
}

Package::~Package() {
    for (int i = 0; i < products.size(); i++) {
        delete products.at(i);
    }
    products.clear();
}
