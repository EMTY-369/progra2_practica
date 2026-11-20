//
// Created by User on 19/11/2026.
//

#ifndef INC_2026_2_LAB8_ADAPTADO__STANDARDPACKAGE_HPP
#define INC_2026_2_LAB8_ADAPTADO__STANDARDPACKAGE_HPP
#include "Package.hpp"

class StandardPackage : public Package{
public:
    bool is_urgent() const;
    void set_urgent(const bool urgent);

    double calculate_cost() override;
    bool can_dispatch() override;
    void leer(ifstream &input) override;
    void imprimir(ofstream &output) override;

    StandardPackage();
    ~StandardPackage() = default;
private:
    bool urgent;
};


#endif //INC_2026_2_LAB8_ADAPTADO__STANDARDPACKAGE_HPP
