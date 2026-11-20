//
// Created by User on 19/11/2026.
//

#include "StandardPackage.hpp"

bool StandardPackage::is_urgent() const {
    return urgent;
}

void StandardPackage::set_urgent(const bool urgent) {
    this->urgent = urgent;
}

double StandardPackage::calculate_cost() {
    return 10 + 2*Package::get_total_weight() + 0.05*Package::get_distance() + (urgent)*8;
}

bool StandardPackage::can_dispatch() {
    return Package::get_total_weight()<=20 and Package::get_distance()<=500;
}

void StandardPackage::leer(ifstream &input) {
    Package::leer(input);
    input >> urgent;
    input.get();
}

void StandardPackage::imprimir(ofstream &output) {
    output<<"PACKAGE TYPE: STANDARD"<<endl;
    output<<"Package: "<<Package::get_code()<<endl;
    output<<"Distance: "<<Package::get_distance()<<" km"<<endl;
    output<<"Urgent: ";
    if (urgent) output<<"Yes"<<endl;
    else output<<"No"<<endl;
    output<<"Total weight: "<<Package::get_total_weight()<<" kg"<<endl;
    output<<"Total value: S/ "<<Package::get_total_value()<<endl;
    output<<"Shipping cost: S/ "<<calculate_cost()<<endl;
    output<<"Status: ";
    if (can_dispatch()) output<<"DISPATCHED"<<endl<<endl;
    else output<<"PENDING"<<endl<<endl;

    Package::imprimir(output);
}

StandardPackage::StandardPackage() {
    urgent = false;
}
