//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__REFRIGERATEPACKAGE_HPP
#define INC_2026_2_LAB8_ADAPTADO__REFRIGERATEPACKAGE_HPP
#include "Package.hpp"

class RefrigeratePackage : public Package {
public:
    double get_temperature() const;
    void set_temperature(const double temperature);

    bool can_dispatch() override;
    double calculate_cost() override;
    void leer(ifstream &input) override;
    void imprimir(ofstream &output) override;

    RefrigeratePackage();
    ~RefrigeratePackage() = default;
private:
    double temperature;
};


#endif //INC_2026_2_LAB8_ADAPTADO__REFRIGERATEPACKAGE_HPP
