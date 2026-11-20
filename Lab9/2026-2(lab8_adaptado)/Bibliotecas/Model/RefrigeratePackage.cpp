//
// Created by User on 19/11/2026.
//

#include "RefrigeratePackage.hpp"

double RefrigeratePackage::get_temperature() const {
    return temperature;
}

void RefrigeratePackage::set_temperature(const double temperature) {
    this->temperature = temperature;
}

bool RefrigeratePackage::can_dispatch() {
    return Package::get_total_weight()<=10 and Package::get_distance()<=300 and (temperature>=-10 and temperature<=8);
}

double RefrigeratePackage::calculate_cost() {
    return 20 + 3*Package::get_total_weight() + 0.08*Package::get_distance() + 1.5*(8-temperature);
}

void RefrigeratePackage::leer(ifstream &input) {
    Package::leer(input);
    input>>temperature;
    input.get();
}

void RefrigeratePackage::imprimir(ofstream &output) {
    output<<"PACKAGE TYPE: REFRIGERATED"<<endl;
    output<<"Package: "<<Package::get_code()<<endl;
    output<<"Distance: "<<Package::get_distance()<<" km"<<endl;
    output<<"Required temperature: "<<temperature<<" C"<<endl;
    output<<"Total weight: "<<Package::get_total_weight()<<" kg"<<endl;
    output<<"Total value: S/ "<<Package::get_total_value()<<endl;
    output<<"Shipping cost: S/ "<<calculate_cost()<<endl;
    output<<"Status: ";
    if (can_dispatch()) output<<"DISPATCHED"<<endl<<endl;
    else output<<"PENDING"<<endl<<endl;

    Package::imprimir(output);
}

RefrigeratePackage::RefrigeratePackage() {
    temperature = 0;
}
