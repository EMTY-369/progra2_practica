//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__PRODUCT_HPP
#define INC_2026_2_LAB8_ADAPTADO__PRODUCT_HPP
#include "../Utils/Utils.hpp"

class Product {
public:
    string get_code() const;
    void set_code(const string &code);
    string get_name() const;
    void set_name(const string &name);
    double get_weight() const;
    void set_weight(const double weight);
    double get_value() const;
    void set_value(const double value);

    void leer(ifstream & input);
    void imprimir(ofstream & output);

    Product();
    ~Product() = default;
private:
    string code;
    string name;
    double weight;
    double value;
};


#endif //INC_2026_2_LAB8_ADAPTADO__PRODUCT_HPP
