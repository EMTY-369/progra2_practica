//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__PACKAGE_HPP
#define INC_2026_2_LAB8_ADAPTADO__PACKAGE_HPP
#include "Product.hpp"

class Package {
public:
    int get_n_products() const;
    void set_n_products(const int n_products);
    string get_code() const;
    void set_code(const string &code);
    double get_distance() const;
    void set_distance(const double distance);
    double get_total_weight() const;
    void set_total_weight(const double total_weight);
    double get_total_value() const;
    void set_total_value(const double total_value);

    virtual double calculate_cost() = 0;
    virtual bool can_dispatch() = 0;
    virtual void leer(ifstream & input);
    void leer_productos(ifstream &input);
    virtual void imprimir(ofstream &output);

    Package();
    virtual ~Package();
private:
    string code;
    double distance;
    vector<class Product*> products;
    int n_products;
    double total_weight;
    double total_value;
};


#endif //INC_2026_2_LAB8_ADAPTADO__PACKAGE_HPP
