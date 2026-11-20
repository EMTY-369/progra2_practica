//
// Created by User on 19/11/2026.
//

#include "Product.hpp"

string Product::get_code() const {
    return code;
}

void Product::set_code(const string &code) {
    this->code = code;
}

string Product::get_name() const {
    return name;
}

void Product::set_name(const string &name) {
    this->name = name;
}

double Product::get_weight() const {
    return weight;
}

void Product::set_weight(const double weight) {
    this->weight = weight;
}

double Product::get_value() const {
    return value;
}

void Product::set_value(const double value) {
    this->value = value;
}

void Product::leer(ifstream &input) {
    getline(input,code, ',');
    getline(input,name,',');
    input >> weight;
    input.get();
    input >> value;
    input.get();
}

void Product::imprimir(ofstream &output) {
    output<<left<<setw(20)<<code<<setw(20)<<name<<right<<setw(8)<<weight<<setw(21)<<value<<endl;
}

Product::Product() {
    weight = 0;
    value = 0;
}
