//
// Created by User on 4/11/2026.
//

#ifndef INC_2026_1__LAB5__CONTROL_HPP
#define INC_2026_1__LAB5__CONTROL_HPP
#include "Cita.hpp"

class Control : public Cita {
public:
    double get_costo() const;
    void set_costo(const double costo);
    int get_codmed() const;
    void set_codmed(const int codmed);

    void leer(ifstream &input);
    void imprimir(ofstream & output);
    static int comparar(const void * a, const void * b);

    Control();
    Control(const class Control &origin);
    ~Control()=default;

private:
    double costo;
    int codmed;
};


#endif //INC_2026_1__LAB5__CONTROL_HPP
